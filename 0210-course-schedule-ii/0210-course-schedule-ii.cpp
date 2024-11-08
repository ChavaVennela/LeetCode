class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);
        map<int, vector<int>>m;
        queue<int>q;
        vector<int>ans;
        for(int i=0; i<prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int i=0; i<m[temp].size(); i++){
                indegree[m[temp][i]]--;
                if(indegree[m[temp][i]]==0){
                    q.push(m[temp][i]);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        vector<int>b;
        return b;
    }
};