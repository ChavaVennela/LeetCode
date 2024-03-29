class Graph {
public:
    vector<vector<pair<int, int>>>adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(auto e: edges){
            adjList[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1], edge[2]});
        
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int>cost(adjList.size(), INT_MAX);
        cost[node1]=0;
        pq.push({0, node1});
        while(!pq.empty()){
            int currCost=pq.top()[0];
            int currNode=pq.top()[1];
            pq.pop();
            if(currCost>cost[currNode]){
                continue;
            }
            if(currNode==node2){
                return currCost;
            }
            for(int i=0; i<adjList[currNode].size(); i++){
                int nextNode=adjList[currNode][i].first;
                int cost1=adjList[currNode][i].second;
                int newcost=currCost+cost1;
                if(newcost<cost[nextNode]){
                    cost[nextNode]=newcost;
                    pq.push({newcost, nextNode});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */