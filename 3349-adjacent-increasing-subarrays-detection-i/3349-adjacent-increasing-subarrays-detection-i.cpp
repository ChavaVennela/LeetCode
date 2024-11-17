class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            int flag=0;
            if(i+k+k-1>=nums.size()){
                break;
            }
            for(int j=i+1; j<i+k && j<nums.size(); j++){
                if(nums[j]<=nums[j-1]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                for(int j=i+k+1; j<(i+k+k) && j<nums.size(); j++){
                    if(nums[j]<=nums[j-1]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    return true;
                }
            }
        }
        return false;
    }
};