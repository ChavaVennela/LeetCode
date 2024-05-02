class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[i]<0 && nums[j]>0 && abs(nums[i])==abs(nums[j])){
                return nums[j];
            }
            else{
                if(nums[i]>0 || nums[j]<0){
                    return -1;
                }
                else if(abs(nums[i])>nums[j]){
                    i++;
                }
                else if(abs(nums[i])<nums[j]){
                    j--;
                }
            }
        }
        return -1;
    }
};