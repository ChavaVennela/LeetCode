class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>nums1;
        for(int i=0; i<nums.size(); i++){
            nums1.push_back(nums[i]);
        }
        int found, found1;
        sort(nums1.begin(), nums1.end());
        for(int i=0; i<nums1.size(); i++){
            int a = target - nums1[i], count=0;
            for(int j=nums1.size()-1; j>i; j--){
                if(nums1[j] == a){
                    count = 1;
                    found= nums1[i];
                    found1 = nums1[j];
                    break;
                }
            }
            if(count == 1){
                break;
            }
        }
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == found){
                ans.push_back(i);
                break;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == found1 && ans[0] != i){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};