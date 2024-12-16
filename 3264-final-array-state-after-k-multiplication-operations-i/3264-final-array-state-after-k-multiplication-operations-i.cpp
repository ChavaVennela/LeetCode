class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp=[](pair<int, int>a, pair<int, int>b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            return a.second>b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pq(cmp);
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
        }
        for(int i=0; i<k; i++){
            pair<int, int>temp=pq.top();
            pq.pop();
            pq.push({temp.first*multiplier, temp.second});
        }
        vector<int>ans(nums.size(), 0);
        while(!pq.empty()){
            pair<int, int>temp=pq.top();
            pq.pop();
            ans[temp.second]=temp.first;
        }
        return ans;
    }
};