class Solution {
public:
    map<int, int>a;
    int coms(vector<int>nums, int remain){
        if(remain == 0){
            return 1;
        }
        if(a.find(remain)!=a.end()){
            return a[remain];
        }
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(remain>=nums[i]){
                ans+=coms(nums, remain-nums[i]);
            }
        }
        a[remain]=ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return coms(nums, target);
    }
};