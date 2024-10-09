class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans=INT_MIN;
        for(int i=0; i<k; i++){
            long left=0, right = INT_MAX-1;
            while(left<right){
                long mid=(left+right+1)/2;
                long temp=0;
                for(int j=0; j<n; j++){
                    temp+=max((long)(mid*composition[i][j])-stock[j], (long)0)*cost[j];
                }
                if(temp<=budget){
                    left=mid;
                }
                else{
                    right=mid-1;
                }
            }
            ans=(int)max((long)ans, left);
        }
        return ans;
    }
};