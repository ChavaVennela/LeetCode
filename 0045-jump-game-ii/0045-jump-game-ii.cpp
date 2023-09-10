class Solution {
public:
    vector<int>a;
    int cal(vector<int>&nums, int pos){
        if(pos>=nums.size()-1){
            return 0;
        }
        if(a[pos]!=-1){
            return a[pos];
        }
        int jumps=100000;
        for(int i=1; i<=nums[pos]; i++){
            jumps = min(jumps, 1+cal(nums, pos+i));
        }
        a[pos]=jumps;
        return jumps;
    }
    int jump(vector<int>& nums) {
        a.resize(nums.size(), -1);
        return cal(nums, 0);
    }
};