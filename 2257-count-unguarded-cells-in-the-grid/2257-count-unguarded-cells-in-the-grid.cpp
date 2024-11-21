class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m, vector<int>(n, 0));
        for(int i=0; i<walls.size(); i++){
            grid[walls[i][0]][walls[i][1]]=1;
        }
        for(int i=0; i<guards.size(); i++){
            grid[guards[i][0]][guards[i][1]]=2;
        }
        for(int i=0; i<guards.size(); i++){
            int temp=guards[i][0];
            int temp1=guards[i][1];
            for(int row=temp-1; row>=0; row--){
                if(grid[row][temp1]==1 || grid[row][temp1]==2){
                    break;
                }
                grid[row][temp1]=3;
            }
            for(int row=temp+1; row<grid.size(); row++){
                if(grid[row][temp1]==1 || grid[row][temp1]==2){
                    break;
                }
                grid[row][temp1]=3; 
            }
            for(int col=temp1-1; col>=0; col--){
                if(grid[temp][col]==1 || grid[temp][col]==2){
                    break;
                }
                grid[temp][col]=3;
            }
            for(int col=temp1+1; col<grid[0].size(); col++){
                if(grid[temp][col]==1 || grid[temp][col]==2){
                    break;
                }
                grid[temp][col]=3; 
            }
        }
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};