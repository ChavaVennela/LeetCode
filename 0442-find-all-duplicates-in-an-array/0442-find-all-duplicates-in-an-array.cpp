class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>count(nums.size(), 0);
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]-1]++;
            if(count[nums[i]-1]>1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};