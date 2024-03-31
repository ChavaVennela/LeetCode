class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0, count=0, count1=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            count+=nums[i];
            while(count>=target){
                count-=nums[start];
                count1=min(count1, i-start+1);
                start++;
            }
        }
        if(count1==INT_MAX){
            return 0;
        }
        return count1;
    }
};