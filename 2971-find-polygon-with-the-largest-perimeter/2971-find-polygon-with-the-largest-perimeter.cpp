class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans=-1;
        vector<long long>pref;
        sort(nums.begin(), nums.end());
        pref.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            pref.push_back(pref[i-1]+nums[i]);
        }
        for(int i=2; i<pref.size(); i++){
            if(nums[i]<pref[i-1]){
                ans=pref[i];
            }
        }
        return ans;
    }
};