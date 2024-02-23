class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start=0;
        vector<string>ans;
        if(nums.size()==0){
            return ans;
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[i-1]+1){
                if(start==i-1){
                    ans.push_back(to_string(nums[start]));
                }
                else{
                    string s=to_string(nums[start])+"->"+to_string(nums[i-1]);
                    ans.push_back(s);
                }
                start=i;
            }
        }
        if(start==nums.size()-1){
            ans.push_back(to_string(nums[start]));
        }
        else{
            string s=to_string(nums[start])+"->"+to_string(nums[nums.size()-1]);
            ans.push_back(s);
        }
        return ans;
    }
};