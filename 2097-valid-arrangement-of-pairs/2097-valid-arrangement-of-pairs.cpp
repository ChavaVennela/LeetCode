class Solution {
public:
    void dfs(int node, vector<int>&result, unordered_map<int, deque<int>>&adj){
        while(!adj[node].empty()){
            int nextnode=adj[node].front();
            adj[node].pop_front();
            dfs(nextnode, result, adj);
        }
        result.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>>adj;
        unordered_map<int, int>indegree;
        unordered_map<int, int>outdegree;
        for(int i=0; i<pairs.size(); i++){
            int start=pairs[i][0], end=pairs[i][1];
            adj[start].push_back(end);
            indegree[end]++;
            outdegree[start]++;
        }
        vector<int>result;
        int startnode=pairs[0][0];
        for(auto it=outdegree.begin(); it!=outdegree.end(); it++){
            if(indegree[it->first]+1==it->second){
                startnode=it->first;
                break;
            }
        }
        dfs(startnode, result, adj);
        reverse(result.begin(), result.end());
        vector<vector<int>>ans;
        for(int i=1; i<result.size(); i++){
            ans.push_back({result[i-1], result[i]});
        }
        return ans;
    }
};