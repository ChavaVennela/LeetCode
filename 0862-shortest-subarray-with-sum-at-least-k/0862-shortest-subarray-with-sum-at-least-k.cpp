class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX;
        long long temp = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>prefixSumHeap;
        for (int i = 0; i < nums.size(); i++) {
            temp += nums[i];
            if(temp >= k) {
                ans = min(ans, i + 1);
            }
            while (!prefixSumHeap.empty() && temp - prefixSumHeap.top().first >= k) {
                ans =min(ans, i - prefixSumHeap.top().second);
                prefixSumHeap.pop();
            }
            prefixSumHeap.emplace(temp, i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};