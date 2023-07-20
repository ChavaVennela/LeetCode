class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(), false);
        map<int, unordered_set<int>>mymap;
        int i, j;
        for(i=0; i<rooms.size(); i++){
            for(j=0; j<rooms[i].size(); j++){
                mymap[i].insert(rooms[i][j]);
            }
        }
        queue<int>a;
        a.push(0);
        while(!a.empty()){
            int temp=a.front();
            a.pop();
            visited[temp]=true;
            for(auto itr=mymap[temp].begin(); itr!=mymap[temp].end(); itr++){
                if(!visited[*itr]){
                    visited[*itr]=true;
                    a.push(*itr);
                }
            }
        }
        for(i=0; i<rooms.size(); i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};