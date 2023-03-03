class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int i;
        for(i=0; i<nums.size(); i++){
            string temp=to_string(nums[i]);
            for(int j=0; j<temp.size(); j++){
                ans.push_back((temp[j])-'0');
            }
        }
        return ans;
    }
};