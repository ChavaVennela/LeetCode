class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0, temp=0;
        for(int i=0; i<k; i++){
            ans+=nums[i];
        }
        int at=0;
        temp=ans;
        for(int i=k; i<nums.size(); i++){
            temp+=(nums[i]-nums[at]);
            at++;
            ans=max(ans, temp);
        }
        return ans/k;
    }
};