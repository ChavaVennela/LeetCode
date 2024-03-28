class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0, j=0, count=0;
        map<int, int>freq;
        while(j<nums.size()){
            freq[nums[j]]++;
            if(freq[nums[j]]>k){
                while(freq[nums[j]]>k){
                    freq[nums[i]]--;
                    i++;
                }
            }
            count=max(count, j-i+1);
            j++;
        }
        count=max(count, j-i);
        return count;
    }
};