class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans=0, prefix=0, i;
        for(i=0; i<nums.size(); i++){
            prefix+=nums[i];
            ans= max(ans, (long long)ceil((1.0*prefix)/(i+1)));
        }
        return ans;
    }
};