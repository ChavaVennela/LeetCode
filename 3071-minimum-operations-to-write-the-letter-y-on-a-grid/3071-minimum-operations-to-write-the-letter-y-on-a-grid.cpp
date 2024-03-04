class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<int>ycount(3, 0);
        vector<int>noycount(3, 0);
        int center=grid.size()/2;
        int count=0, count1=0;
        for(int i=0; i<=center; i++){
            if(grid[i][i]>=0){
                ycount[grid[i][i]]++;
                grid[i][i]=-1;
                count++;
            }
            if(grid[center+i][center]>=0){
                ycount[grid[center+i][center]]++;
                grid[center+i][center]=-1;
                count++;
            }
            if(grid[center-i][center+i]>=0){
                ycount[grid[center-i][center+i]]++;
                grid[center-i][center+i]=-1;
                count++;
            }
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]>=0){
                    noycount[grid[i][j]]++;
                    count1++;
                }
            }
        }
        int max1=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i!=j && ycount[i]+noycount[j]>max1){
                    max1=ycount[i]+noycount[j];
                }
            }
        }
        return count+count1-max1;
    }
};