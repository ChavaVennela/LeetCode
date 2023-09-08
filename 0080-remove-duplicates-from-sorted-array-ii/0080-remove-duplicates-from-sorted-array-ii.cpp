class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1, count=1;
        for(i=1; i<nums.size(); i++){
            if(count!=2){
                if(nums[i]==nums[i-1]){
                    count++;
                    nums[j]=nums[i];
                    j++;
                }
                else{
                    count=1;
                    nums[j]=nums[i];
                    j++;
                }
            }
            else{
                if(nums[i]!=nums[i-1]){
                    count=1;
                    nums[j]=nums[i];
                    j++;
                }
            }
        }
        return j;
    }
};