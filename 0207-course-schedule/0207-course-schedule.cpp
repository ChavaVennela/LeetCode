class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>req(numCourses, 0);
        vector<vector<int>>a(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            a[prerequisites[i][1]].push_back(prerequisites[i][0]);
            req[prerequisites[i][0]]++;
        }
        queue<int>q;
        int visited_count=0;
        for(int i=0; i<numCourses; i++){
            if(req[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            visited_count++;
            for(int i=0; i<a[temp].size(); i++){
                req[a[temp][i]]--;
                if(req[a[temp][i]]==0){
                    q.push(a[temp][i]);
                }
            }
        }
        if(numCourses==visited_count){
            return true;
        }
        return false;
    }
};