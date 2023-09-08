class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, ans=0;
        for(i=0; i<32; i++){
            int bit= 1 << i;
            int count=0;
            for(int j=0; j<nums.size(); j++){
                if((bit & nums[j]) != 0){
                    count++;
                }
            }
            if(count*2 > (nums.size())){
                ans=ans | bit;
            }
        }
        return ans;
    }
};