class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>a(nums.size(), 0);
        a[nums.size()-1]=1;
        for(int i=nums.size()-2; i>=0; i--){
            if(i+nums[i]>=nums.size()-1){
                a[i]=1;
            }
            else{
                int j;
                for(j=1; j<=nums[i]; j++){
                    if(a[i+j]==1){
                        a[i]=1;
                        break;
                    }
                }
            }
        }
        if(a[0]==1){
            return true;
        }
        return false;
    }
};