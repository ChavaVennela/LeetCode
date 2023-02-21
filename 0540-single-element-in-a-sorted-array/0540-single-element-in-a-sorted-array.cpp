class Solution {
public:
    int check(vector<int>nums, int l, int r){
        if(l==r){
            return nums[l];
        }
        else{
            int mid=l+(r-l)/2;
            if(mid-1>=0 && nums[mid-1]==nums[mid]){
                if((r-mid)%2==0){
                    r=mid-2;
                    return check(nums, l, r);
                }
                else{
                    l=mid+1;
                    return check(nums, l, r);
                }
            }
            else if(mid+1<nums.size() && nums[mid+1]==nums[mid]){
                if((r-mid-1)%2==0){
                    r=mid-1;
                    return check(nums, l, r);
                }
                else{
                    l=mid+2;
                    return check(nums, l, r);
                }
            }
            else{
                return nums[mid];
            }
        }
        return nums[l];
    }
    int singleNonDuplicate(vector<int>& nums) {
        return check(nums, 0, nums.size()-1);
    }
};