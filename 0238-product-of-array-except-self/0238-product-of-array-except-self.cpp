class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>forward(nums.size());
        vector<int>back(nums.size());
        vector<int>ans(nums.size());
        int i;
        forward[0]=nums[0];
        back[nums.size()-1]=nums[nums.size()-1];
        for(i=1; i<nums.size(); i++){
            forward[i] = forward[i-1]*nums[i];
            back[nums.size()-1-i]=back[nums.size()-i]*nums[nums.size()-1-i];
        }
        ans[0]=back[1];
        ans[nums.size()-1]=forward[nums.size()-2];
        for(i=1; i<nums.size()-1; i++){
            ans[i]=forward[i-1]*back[i+1];
        }
        return ans;
    }
};