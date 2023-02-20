class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size()-1);
    }
    int find(vector<int>& nums, int target, int l, int r){
        if(l>r){
            return r+1;
        }
        else{
            int mid = l+(r-l+1)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                return find(nums, target, l, mid-1);
            }
            else{
                return find(nums, target, mid+1, r);
            }
        }
    }
};