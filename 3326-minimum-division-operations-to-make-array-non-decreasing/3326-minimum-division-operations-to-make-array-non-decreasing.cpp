class Solution {
public:
    int check(int a){
        for(int i=2; i<a; i++){
            if(a%i==0){
                return i;
            }
        }
        return a;
    }
    
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]>nums[i+1]){
                nums[i]=check(nums[i]);
                if(nums[i]>nums[i+1]){
                    return -1;
                }
                count++;
            }
        }
        return count;
    }
};