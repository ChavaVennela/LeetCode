class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0, ans=0, i;
        vector<long long>a;
        for(i=0; i<nums.size(); i++){
            if(nums[i]==0){
                count++;
            }
            else{
                if(count>0){
                    a.push_back(count);
                    count=0;
                }
            }
        }
        if(count>0){
            a.push_back(count);
        }
        for(i=0; i<a.size(); i++){
            ans+=(pow(a[i], 2)+a[i])/2;
        }
        return ans;
    }
};