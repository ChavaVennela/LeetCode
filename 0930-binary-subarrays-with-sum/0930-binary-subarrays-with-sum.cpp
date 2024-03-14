class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int start=0, zeros=0, current=0, count=0;
        for(int end=0; end<nums.size(); end++){
            current+=nums[end];
            while(start<end && (nums[start]==0 || current>goal)){
                if(nums[start]==1){
                    zeros=0;
                }
                else{
                    zeros++;
                }
                current=current-nums[start];
                start++;
            }
            if(current==goal){
                count+=zeros+1;
            }
        }
        return count;
    }
};