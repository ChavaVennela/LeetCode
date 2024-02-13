class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>>ans(grid.size(), vector<int>(grid[0].size(), 0));
        vector<int>row(grid.size(),0);
        vector<int>col(grid[0].size(), 0);
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                ans[i][j]=2*(row[i]+col[j])-grid.size()-grid[i].size();
            }
        }
        return ans;
    }
};