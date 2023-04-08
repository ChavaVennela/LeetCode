class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int i, j;
        vector<vector<int>>a(mat[0].size());
        vector<vector<int>>b(mat.size());
        for(i=0; i<mat.size(); i++){
            for(j=0; j<mat[i].size(); j++){
                if(i==j){
                    a[0].push_back(mat[i][j]);
                }
                else if(i>j){
                    b[i-j].push_back(mat[i][j]);
                }
                else{
                    a[j-i].push_back(mat[i][j]);
                }
            }
        }
        for(i=0; i<a.size(); i++){
            sort(a[i].begin(), a[i].end());
        }
        for(i=0; i<b.size(); i++){
            sort(b[i].begin(), b[i].end());
        }
        for(i=0; i<mat.size(); i++){
            for(j=0; j<mat[i].size(); j++){
                if(i==j){
                    mat[i][j]=a[0][0];
                    a[0].erase(a[0].begin());
                }
                else if(i>j){
                    mat[i][j]=b[i-j][0];
                    b[i-j].erase(b[i-j].begin());
                }
                else{
                    mat[i][j]=a[j-i][0];
                    a[j-i].erase(a[j-i].begin());
                }
            }
        }
        return mat;
    }
};