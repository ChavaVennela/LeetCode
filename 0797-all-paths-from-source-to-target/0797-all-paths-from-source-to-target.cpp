class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        queue<vector<int>>q;
        vector<int>temp1;
        temp1.push_back(0);
        q.push(temp1);
        while(!q.empty()){
            vector<int>temp=q.front();
            q.pop();
            if(temp[temp.size()-1]==graph.size()-1){
                res.push_back(temp);
                continue;
            }
            for(int i=0; i<graph[temp[temp.size()-1]].size(); i++){
                vector<int>temp2=temp;
                temp2.push_back(graph[temp[temp.size()-1]][i]);
                q.push(temp2);
            }
        }
        return res;
    }
};