class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long count=0, ans=0, j=happiness.size()-1;
        for(long long i=0; i<k; i++){
            if(happiness[j]>=i){
                ans=(ans+happiness[j]-i);
            }
            else{
                break;
            }
            j--;
        }
        return ans;
    }
};