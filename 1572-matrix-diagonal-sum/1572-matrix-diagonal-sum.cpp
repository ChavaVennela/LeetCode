class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i, j, ans=0;
        for(i=0; i<mat.size(); i++){
            ans=ans+mat[i][i];
            for(j=0; j<mat.size(); j++){
                if(i+j == mat.size()-1 && i!=j){
                    ans=ans+mat[i][j];
                }
            }
        }
        return ans;
    }
};