class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0, j=0, prod=1, count=0;
        while(j<nums.size()){
            prod=prod*nums[j];
            if(prod<k){
                count=count+(j-i+1);
            }
            else{
                while(prod>=k && i<=j){
                    prod=prod/nums[i];
                    i++;
                }
                count=count+(j-i+1);
            }
            j++;
        }
        return count;
    }
};