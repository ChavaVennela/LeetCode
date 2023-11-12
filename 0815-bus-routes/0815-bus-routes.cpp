class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        unordered_map<int, vector<int>>a;
        for(int i=0; i<routes.size(); i++){
            for(int j=0; j<routes[i].size(); j++){
                a[routes[i][j]].push_back(i);
            }
        }
        vector<int>visited(routes.size(), 0);
        queue<int>q;
        for(int i=0; i<a[source].size(); i++){
            q.push(a[source][i]);
            visited[a[source][i]]=1;
        }
        int count=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                int temp=q.front();
                q.pop();
                for(int j=0; j<routes[temp].size(); j++){
                    if(routes[temp][j]==target){
                        return count;
                    }
                    for(int k=0; k<a[routes[temp][j]].size(); k++){
                        if(visited[a[routes[temp][j]][k]]==0){
                            visited[a[routes[temp][j]][k]]=1;
                            q.push(a[routes[temp][j]][k]);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
        
    }
};