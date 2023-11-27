class Solution {
public:
    vector<vector<int>>a, dp;
    int given_n;
    int count(int pos, int curr_len){
        if(curr_len==given_n){
            return 1;
        }
        if(dp[pos][curr_len]!=-1){
            return dp[pos][curr_len];
        }
        int temp=0;
        for(int i=0; i<a[pos].size(); i++){
            dp[a[pos][i]][curr_len+1]=count(a[pos][i], curr_len+1);
            temp=(temp+dp[a[pos][i]][curr_len+1])%1000000007;
        }
        dp[pos][curr_len]=temp;
        return dp[pos][curr_len];
    }
    int knightDialer(int n) {
        given_n=n;
        dp.resize(10, vector<int>(n+1, -1));
        a.resize(10);
        a[0]={4, 6};
        a[1]={6, 8};
        a[2]={7, 9};
        a[3]={4, 8};
        a[4]={0, 3, 9};
        a[5]={};
        a[6]={0, 1, 7};
        a[7]={2, 6};
        a[8]={1, 3};
        a[9]={2, 4};
        int ans=0;
        for(int i=0; i<10; i++){
            ans=(ans+count(i, 1))%1000000007;
        }
        return ans;
    }
};