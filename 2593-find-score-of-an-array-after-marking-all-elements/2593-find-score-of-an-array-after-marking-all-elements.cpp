class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        auto cmp=[] (pair<int, int>a, pair<int, int>b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            return a.second>b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pq(cmp);
        vector<bool>visited(nums.size(), false);
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
        }
        while(!pq.empty()){
            pair<int, int>temp=pq.top();
            pq.pop();
            if(visited[temp.second]){
                continue;
            }
            ans+=temp.first;
            visited[temp.second]=true;
            if(temp.second-1>=0){
                visited[temp.second-1]=true;
            }
            if(temp.second+1<nums.size()){
                visited[temp.second+1]=true;
            }
        }
        return ans;
    }
};