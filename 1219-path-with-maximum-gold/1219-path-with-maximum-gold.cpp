class Solution {
public:
    int check(vector<vector<int>>&grid, int row, int col){
        if(grid[row][col]<=0){
            return 0;
        }
        int ans=grid[row][col], left=0, right=0, up=0, down=0;
        grid[row][col]=-1;
        if(row+1<grid.size()){
            right=check(grid, row+1, col);
        }
        if(row-1>=0){
            left=check(grid, row-1, col);
        }
        if(col+1<grid[row].size()){
            down=check(grid, row, col+1);
        }
        if(col-1>=0){
            up=check(grid, row, col-1);
        }
        grid[row][col]=ans;
        return ans+max(right, max(left, max(up, down)));
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                int temp=check(grid, i, j);
                count=max(count, temp);
            }
        }
        return count;
    }
};