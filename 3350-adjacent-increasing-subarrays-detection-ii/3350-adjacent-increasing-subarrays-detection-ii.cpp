class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<pair<int, int>>a;
        int start=0, end=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                end=i;
            }
            else{
                a.push_back({start, end});
                start=i;
                end=i;
            }
        }
        a.push_back({start, end});
        if(a.size()==1){
            return (a[0].second-a[0].first+1)/2;
        }
        int ans=(a[0].second-a[0].first+1)/2;
        for(int i=1; i<a.size(); i++){
            if(a[i].first==a[i-1].second+1){
                ans=max(ans, min(a[i].second-a[i].first+1, a[i-1].second-a[i-1].first+1));
            }
            ans=max(ans, (a[i].second-a[i].first+1)/2);
        }
        return ans;
    }
};