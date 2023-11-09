class Solution {
public:
    int mul(int a, int b, int mod){ 
        int res = 0; 
        a %= mod; 
        while(b){ 
            if(b & 1){ 
                res = (res + a) % mod;
            } 
            a = (2 * a) % mod; 
            b >>= 1; 
        } 
        return res; 
    } 
    int countHomogenous(string s) {
        long long ans=0, count=1;
        vector<int>a;
        for(int i=1; i<s.size(); i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                a.push_back(count);
                count=1;
            }
        }
        a.push_back(count);
        for(int i=0; i<a.size(); i++){
            ans=(ans+((mul(a[i], a[i]+1, 1000000007))/2))%1000000007;
        }
        return ans;
    }
};