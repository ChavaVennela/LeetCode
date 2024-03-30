class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max1=0, start=0, count1=0;
        for(int i=0; i<nums.size(); i++){
            max1=max(nums[i], max1);
        }
        long long count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==max1){
                count1++;
            }
            while(count1==k){
                if(nums[start]==max1){
                    count1--;
                }
                start++;
            }
            count+=start;
        }
        return count;
    }
};