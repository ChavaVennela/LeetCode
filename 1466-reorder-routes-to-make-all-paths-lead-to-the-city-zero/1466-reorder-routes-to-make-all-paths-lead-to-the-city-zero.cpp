class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>visited(n, 0);
        map<int, unordered_set<int>>mymap;
        map<int, unordered_set<int>>mymap1;
        for(int i=0; i<connections.size(); i++){
            mymap[connections[i][0]].insert(connections[i][1]);
            mymap1[connections[i][1]].insert(connections[i][0]);
        }
        queue<int>a;
        a.push(0);
        int i=0, ans=0;
        while(!a.empty()){
            int temp=a.front();
            a.pop();
            if(visited[temp]==0 || visited[temp]==1){
                visited[temp]=2;
            }
            else{
                continue;
            }
            for(auto temp1=mymap1[temp].begin(); temp1!=mymap1[temp].end(); temp1++){
                visited[*temp1]=1;
                a.push(*temp1);
            }
            if(mymap[temp].size()!=0){
                for(auto temp1=mymap[temp].begin(); temp1!=mymap[temp].end(); temp1++){
                    if(visited[*temp1]==0){
                        ans++;
                        visited[*temp1]=1;
                        a.push(*temp1);
                    }
                }
            }
            
        }
        return ans;
    }
};