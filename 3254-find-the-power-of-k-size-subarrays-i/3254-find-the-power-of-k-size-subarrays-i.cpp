class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        vector<int>ans;
        for(int i=0; i<nums.size()-k+1; i++){
            ans.push_back(-1);
            for(int j=i+1; j<i+k && j<nums.size(); j++){
                if(nums[j]==nums[j-1]+1){
                    ans[i]=max(ans[i], nums[j]);
                }
                else{
                    ans[i]=-1;
                    break;
                }
            }
        }
        return ans;
    }
};