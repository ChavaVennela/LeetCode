class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left=0, ans=0;
        long curr=0;
        for(int i=0; i<nums.size(); i++){
            long target=nums[i];
            curr+=target;
            while((i-left+1)*target-curr>k){
                curr-=nums[left];
                left++;
            }
            ans=max(ans, i-left+1);
        }
        return ans;
    }
};