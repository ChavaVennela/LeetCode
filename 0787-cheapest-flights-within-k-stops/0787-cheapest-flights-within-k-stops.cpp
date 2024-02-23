class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<int>>adj;
        map<pair<int, int>, int>price;
        map<pair<int, int>, int>visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back(flights[i][1]);
            price[{flights[i][0],flights[i][1]}]=flights[i][2];
            visited[{flights[i][0],flights[i][1]}]=0;
        }
        for(int i=0; i<adj[src].size(); i++){
            vector<int>temp1;
            temp1.push_back(price[{src, adj[src][i]}]);
            temp1.push_back(adj[src][i]);
            temp1.push_back(0);
            temp1.push_back(src);
            pq.push(temp1);
        }
        while(!pq.empty()){
            vector<int>temp=pq.top();
            pq.pop();
            if(temp[1]==dst){
                return temp[0];
            }
            visited[{temp[3],temp[1]}]=1;
            if(temp[2]!=k){
                for(int i=0; i<adj[temp[1]].size(); i++){
                    if(visited[{temp[1], adj[temp[1]][i]}]!=1 && ((temp[2]==k-1 && adj[temp[1]][i]==dst)||temp[2]<k-1)){
                        vector<int>temp1;
                        temp1.push_back(temp[0]+price[{temp[1], adj[temp[1]][i]}]);
                        temp1.push_back(adj[temp[1]][i]);
                        temp1.push_back(temp[2]+1);
                        temp1.push_back(temp[1]);
                        pq.push(temp1);
                    }
                }
            }
        }
        return -1;
    }
};