class Solution {
public:
    int check(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(row>=matrix.size()){
            return 0;
        }
        if(col>=matrix[0].size()){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        if(matrix[row][col]==0){
            return 0;
        }
        int down=check(row+1, col, matrix, dp);
        int right=check(row, col+1, matrix, dp);
        int diag=check(row+1, col+1, matrix, dp);
        dp[row][col]=1+min(right, min(down, diag));
        return dp[row][col];
    }
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                ans+=check(i, j, matrix, dp);
            }
        }
        return ans;
    }
};