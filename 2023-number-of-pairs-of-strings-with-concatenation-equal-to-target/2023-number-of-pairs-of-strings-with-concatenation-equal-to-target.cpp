class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int>m;
        int i, count=0;
        for(i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(i=0; i<nums.size(); i++){
            if(target.substr(0, nums[i].size())==nums[i] && m.find(target.substr(nums[i].size()))!=m.end()){
                if(nums[i]==target.substr(nums[i].size())){
                    count+=m[nums[i]]-1;
                }
                else{
                    count+=m[target.substr(nums[i].size())];
                }
            }
        }
        return count;
    }
};