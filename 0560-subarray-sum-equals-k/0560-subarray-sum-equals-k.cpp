class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>a;
        int sum=0, count=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
            if(a.find(sum-k)!=a.end()){
                count+=a[sum-k];
            }
            a[sum]++;
        }
        return count;
    }
};