class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<set<int>>a;
        set<int>tep;
        tep.insert(0);
        a.push_back(tep);
        vector<int>visit(n, 0);
        visit[0]=1;
        queue<pair<int, int>>q;
        q.push({0,0});
        while(!q.empty()){
            pair<int, int>val=q.front();
            q.pop();
            for(int i=0; i<edges.size(); i++){
                if(edges[i][0]==val.first && visit[edges[i][1]]==0){
                    a[val.second].insert(edges[i][1]);
                    visit[edges[i][1]]=1;
                    q.push({edges[i][1], val.second});
                }
                else if(edges[i][1]==val.first && visit[edges[i][0]]==0){
                    a[val.second].insert(edges[i][0]);
                    visit[edges[i][0]]=1;
                    q.push({edges[i][0], val.second});
                }
            }
            if(q.empty()){
                for(int i=0; i<n; i++){
                    if(visit[i]==0){
                        set<int>temp;
                        temp.insert(i);
                        a.push_back(temp);
                        q.push({i, a.size()-1});
                        visit[i]=1;
                        break;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<a.size(); i++){
            int val=0;
            for(int j=0; j<edges.size(); j++){
                if(edges[j][0]>=0 && a[i].find(edges[j][0])!=a[i].end()){
                    val++;
                    edges[j][0]=-1;
                    edges[j][1]=-1;
                }
            }
            int val1=a[i].size();
            if((val1*(val1-1))/2 == val){
                ans++;
            }
        }
        return ans;
    }
};