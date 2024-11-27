class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        map<int, vector<int>>a;
        vector<int>ans;
        for(int i=0; i<queries.size(); i++){
            a[queries[i][0]].push_back(queries[i][1]);
            queue<pair<int, int>>q;
            q.push({0,0});
            vector<bool>visited(n, false);
            while(!q.empty()){
                pair<int, int>temp=q.front();
                q.pop();
                if(visited[temp.first]){
                    continue;
                }
                if(temp.first==n-1){
                    if(ans.size()==i){
                        ans.push_back(temp.second);
                    }
                    else{
                        ans[i]=min(ans[i], temp.second);
                    }
                }
                else{
                    if(a.find(temp.first)!=a.end()){
                        for(int j=0; j<a[temp.first].size(); j++){
                            q.push({a[temp.first][j], temp.second+1});
                        }
                    }
                    q.push({temp.first+1, temp.second+1});
                }
                visited[temp.first]=true;
            }
        }
        return ans;
    }
};