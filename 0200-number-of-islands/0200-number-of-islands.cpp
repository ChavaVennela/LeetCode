class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i, j, count=0;
        //vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(i=0; i<grid.size(); i++){
            for(j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    queue<pair<int, int>>q;
                    grid[i][j]='0';
                    q.push({i, j});
                    int l, p;
                    while(!q.empty()){
                        l=q.front().first;
                        p=q.front().second;
                        q.pop();
                        if(l>0 && grid[l-1][p]=='1'){
                            q.push({l-1, p});
                            grid[l-1][p]='0';
                        }
                        if(p>0 && grid[l][p-1]=='1'){
                            q.push({l, p-1});
                            grid[l][p-1]='0';
                        }
                        if(l<grid.size()-1 && grid[l+1][p]=='1'){
                            q.push({l+1, p});
                            grid[l+1][p]='0';
                        }
                        if(p<grid[0].size()-1 && grid[l][p+1]=='1'){
                            q.push({l, p+1});
                            grid[l][p+1]='0';
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};