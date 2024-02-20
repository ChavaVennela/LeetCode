class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumcount=(nums.size()*(nums.size()+1))/2;
        for(int i=0; i<nums.size(); i++){
            sumcount-=nums[i];
        }
        return sumcount;
    }
};