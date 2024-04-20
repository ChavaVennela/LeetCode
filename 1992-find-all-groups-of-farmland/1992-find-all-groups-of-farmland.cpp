class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int curr=1;
        for(int i=0; i<land.size(); i++){
            for(int j=0; j<land[i].size(); j++){
                if(land[i][j]==1){
                    if(i-1>=0 && land[i-1][j]>1){
                        land[i][j]=land[i-1][j];
                    }
                    else if(j-1>=0 && land[i][j-1]>1){
                        land[i][j]=land[i][j-1];
                    }
                    else{
                        curr++;
                        land[i][j]=curr;
                    }
                }
            }
        }
        ans.resize(curr-1, vector<int>(4, INT_MAX));
        for(int i=0; i<land.size(); i++){
            for(int j=0; j<land[i].size(); j++){
                if(land[i][j]>1){
                    if(ans[land[i][j]-2][0]==INT_MAX){
                        ans[land[i][j]-2][0]=i;
                        ans[land[i][j]-2][1]=j;
                        ans[land[i][j]-2][2]=i;
                        ans[land[i][j]-2][3]=j;
                    }
                    else{
                        ans[land[i][j]-2][0]=min(i, ans[land[i][j]-2][0]);
                        ans[land[i][j]-2][1]=min(j, ans[land[i][j]-2][1]);
                        ans[land[i][j]-2][2]=max(i, ans[land[i][j]-2][2]);
                        ans[land[i][j]-2][3]=max(j, ans[land[i][j]-2][3]);
                    }
                }
            }
        }
        return ans;
    }
};