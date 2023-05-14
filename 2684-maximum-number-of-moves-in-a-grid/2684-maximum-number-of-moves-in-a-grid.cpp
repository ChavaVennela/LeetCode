class Solution {
public:
    int check(int x, int y, vector<vector<int>>& grid, int last){
        if(x>=grid.size() || y>=grid[0].size() || x<0 || grid[x][y]<=last){
            return 0;
        } 
        int val=grid[x][y];
        grid[x][y]=0;
        return max(check(x, y+1, grid, val), max(check(x-1, y+1, grid, val), check(x+1, y+1, grid, val)))+1;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int i, ans=0;
        for(i=0; i<grid.size(); i++){
            ans=max(ans, check(i, 0, grid, -1));
        }
        return ans-1;
    }
};