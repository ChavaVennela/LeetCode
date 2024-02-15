class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>a(nums.size()-1,0);
        for(int i=1; i<nums.size(); i++){
            a[i-1]=(nums[i]+nums[i-1])%10;
        }
        return triangularSum(a);
    }
};