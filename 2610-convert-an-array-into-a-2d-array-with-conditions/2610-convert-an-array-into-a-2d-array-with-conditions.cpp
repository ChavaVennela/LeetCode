class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        int count=0;
        unordered_map<int, int>a;
        for(int i=0; i<nums.size(); i++){
            a[nums[i]]++;
            if(ans.size()<a[nums[i]]){
                ans.push_back({nums[i]});
            }
            else{
                ans[a[nums[i]]-1].push_back(nums[i]);
            }
        }
        return ans;
    }
};