class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int a=INT_MAX, b=INT_MAX, c=INT_MAX;
                if(j-1>=0){
                    a=matrix[i+1][j-1];
                }
                if(j+1<n){
                    b=matrix[i+1][j+1];
                }
                c=matrix[i+1][j];
                matrix[i][j]+=min(a, min(b, c));
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            ans=min(ans, matrix[0][i]);
        }
        return ans;
    }
};