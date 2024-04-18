class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i, j, count=0;
        for(i=0; i<grid.size(); i++){
            for(j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    if(i-1<0 || grid[i-1][j] == 0){
                        count++;
                    }
                    if(j-1<0 || grid[i][j-1] == 0){
                        count++;
                    }
                    if(j+1==grid[i].size() || grid[i][j+1] == 0){
                        count++;
                    }
                    if(i+1 == grid.size() || grid[i+1][j] == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};