class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>visited(isConnected.size(), 0);
        map<int, unordered_set<int>>mymap;
        int i, j, ans=0;
        for(i=0; i<isConnected.size(); i++){
            for(j=0; j<isConnected.size(); j++){
                if(i!=j && isConnected[i][j]==1){
                    mymap[i].insert(j);
                }
            }
        }
        queue<int>a;
        a.push(0);
        while(!a.empty()){
            int temp=a.front();
            a.pop();
            if(visited[temp]==0){
                ans++;
            }
            visited[temp]=2;
            for(auto itr=mymap[temp].begin(); itr!=mymap[temp].end(); itr++){
                if(visited[*itr]==0){
                    a.push(*itr);
                    visited[*itr]=1;
                }
            }
            if(a.empty()){
                for(i=0; i<visited.size(); i++){
                    if(visited[i]==0){
                        a.push(i);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};