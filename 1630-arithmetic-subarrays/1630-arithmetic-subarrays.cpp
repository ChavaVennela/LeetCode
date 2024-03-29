class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0; i<l.size(); i++){
            vector<int>temp;
            for(int j=l[i]; j<=r[i]; j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            int diff=temp[1]-temp[0], count=0;
            for(int j=1; j<temp.size(); j++){
                if(temp[j]-temp[j-1]!=diff){
                    ans.push_back(false);
                    count=1;
                    break;
                }
            }
            if(count==0){
                ans.push_back(true);
            }
        }
        return ans;
    }
};