class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare=nums[0], tort=nums[0];
        do{
            hare=nums[nums[hare]];
            tort=nums[tort];
        }while(hare!=tort);
        tort=nums[0];
        while(hare!=tort){
            hare=nums[hare];
            tort=nums[tort];
        }
        return hare;
    }
};