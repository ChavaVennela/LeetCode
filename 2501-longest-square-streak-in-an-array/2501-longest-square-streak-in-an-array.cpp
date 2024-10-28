class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int>a(nums.begin(), nums.end());
        int count=0;
        for(int i=0; i<nums.size(); i++){
            long long temp=nums[i];
            int count1=0;
            while(a.find((int)temp)!=a.end()){
                count1++;
                if(temp*temp>1e5){
                    break;
                }
                temp=temp*temp;
            }
            count=max(count, count1);
        }
        if(count<2){
            return -1;
        }
        return count;
    }
};