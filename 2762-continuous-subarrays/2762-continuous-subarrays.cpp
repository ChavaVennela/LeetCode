class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int l=0, r=0;
        map<int, int>a;
        while(r<nums.size()){
            a[nums[r]]++;
            while(abs(a.begin()->first-a.rbegin()->first)>2){
                a[nums[l]]--;
                if(a[nums[l]]==0){
                    a.erase(nums[l]);
                }
                l++;
            }
            ans+= r-l+1;
            r++;
        }
        return ans;
    }
};