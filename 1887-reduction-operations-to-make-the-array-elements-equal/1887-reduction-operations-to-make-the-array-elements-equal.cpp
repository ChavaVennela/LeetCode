class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count=1, ans=0, temp=-1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                continue;
            }
            else{
                temp=i+1;
                break;
            }
        }
        if(temp==-1){
            return 0;
        }
        int temp1=1;
        for(int i=temp+1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                temp1++;
            }
            else{
                ans+=count*temp1;
                temp1=1;
                count++;
            }
        }
        ans+=count*temp1;
        return ans;
    }
};