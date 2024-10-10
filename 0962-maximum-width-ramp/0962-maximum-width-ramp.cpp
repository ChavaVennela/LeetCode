class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
       stack<int>a;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(a.empty() || nums[a.top()]>nums[i]){
                a.push(i);
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            while(!a.empty() && nums[a.top()]<=nums[i]){
                ans=max(ans, i-a.top());
                a.pop();
            }
        }
        return ans;
    }
};