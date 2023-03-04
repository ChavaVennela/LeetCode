class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int count=0, minidx=-1, maxidx=-1, bound=-1, i;
        for(i=0; i<nums.size(); i++){
            if(nums[i]==minK){
                minidx=i;
            }
            if(nums[i]==maxK){
                maxidx=i;
            }
            if(nums[i]>maxK || nums[i]<minK){
                bound=i;
            }
            if(min(minidx, maxidx)-bound>0){
                count=count+(min(minidx, maxidx)-bound);
            }
        }
        return count;
    }
};