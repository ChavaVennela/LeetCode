class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()==1){
            return 0;
        }
        unordered_map<int, vector<int>>a;
        int i;
        for(i=0; i<arr.size(); i++){
            a[arr[i]].push_back(i);
        }
        vector<bool>visited(arr.size(), false);
        visited[0]=true;
        int steps=0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int temp=q.size();
            for(i=0; i<temp; i++){
                int curr=q.front(), j;
                q.pop();
                if(curr==arr.size()-1){
                    return steps;
                }
                if(curr+1<arr.size() && !visited[curr+1]){
                    q.push(curr+1);
                    visited[curr+1]=true;
                }
                if(curr-1>=0 && !visited[curr-1]){
                    q.push(curr-1);
                    visited[curr-1]=true;
                }
                for(j=0; j<a[arr[curr]].size(); j++){
                    if(a[arr[curr]][j]!=curr && !visited[a[arr[curr]][j]]){
                        q.push(a[arr[curr]][j]);
                        visited[a[arr[curr]][j]]=true;
                    }
                }
                a[arr[curr]].clear();
            }
            steps++;
        }
        return steps;
    }
};