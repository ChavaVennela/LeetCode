class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int i, j, count=0, flag=0;
        for(i=0; i<grid.size(); i++){
            for(j=0; j<grid[i].size(); j++){
                if(i==0 && grid[i][j]==1){
                    grid[i][j]=-1;
                }
                if(j==0 && grid[i][j]==1){
                    grid[i][j]=-1;
                }
                if(i==grid.size()-1 && grid[i][j]==1){
                    grid[i][j]=-1;
                }
                if(j==grid[i].size()-1 && grid[i][j]==1){
                    grid[i][j]=-1;
                }
            }
        }
        while(flag<2){
            int check=0;
            if(flag==0){
                for(i=0; i<grid.size(); i++){
                    for(j=0; j<grid[i].size(); j++){
                        if(grid[i][j]==1 && (grid[i-1][j]==-1 || grid[i][j-1]==-1 || grid[i+1][j]==-1 || grid[i][j+1]==-1)){
                            grid[i][j]=-1;
                            check=1;
                        }
                    }
                }
                if(check==0){
                    flag=2;
                }
                else{
                    flag=1;
                }
            }
            else if(flag==1){
                for(i=grid.size()-1; i>=0; i--){
                    for(j=grid[i].size()-1; j>=0; j--){
                        if(grid[i][j]==1){
                            if(grid[i-1][j]==-1 || grid[i][j-1]==-1 || grid[i+1][j]==-1 || grid[i][j+1]==-1){
                                grid[i][j]=-1;
                                check=1;
                            }
                        }
                    }
                }
                if(check==0){
                    flag=2;
                }
                else{
                    flag=0;
                }
            }
        }
        for(i=0; i<grid.size(); i++){
            for(j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};