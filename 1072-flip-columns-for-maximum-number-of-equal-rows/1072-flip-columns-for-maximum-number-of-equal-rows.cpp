class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=0; i<matrix.size(); i++){
            vector<int>temp;
            int count=0;
            for(int j=0; j<matrix[0].size(); j++){
                temp.push_back(1-matrix[i][j]);
            }
            for(int k=0; k<matrix.size(); k++){
                if(matrix[k]==temp || matrix[k]==matrix[i]){
                    count++;
                }
            }
            ans=max(ans, count);
        }
        return ans;
    }
};