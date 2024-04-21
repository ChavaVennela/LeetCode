class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        vector<bool>visited(n, false);
        queue<int>q;
        unordered_map<int, vector<int>>mymap;
        for(int i=0; i<edges.size(); i++){
            mymap[edges[i][0]].push_back(edges[i][1]);
            mymap[edges[i][1]].push_back(edges[i][0]);
        }
        q.push(source);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            visited[temp]=true;
            for(int i=0; i<mymap[temp].size(); i++){
                if(mymap[temp][i]==destination){
                    return true;
                }
                else if(!visited[mymap[temp][i]]){
                    q.push(mymap[temp][i]);
                    visited[mymap[temp][i]]=true;
                }
            }
        }
        return false;
    }
};