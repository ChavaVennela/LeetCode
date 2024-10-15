class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long ans=0;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        for(int i=0; i<k; i++){
            ans+=pq.top();
            int temp=pq.top();
            pq.pop();
            pq.push(ceil((double)temp/3));
        }
        return ans;
    }
};