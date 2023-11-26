class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>a(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(i==0 && matrix[i][j]==1){
                    a[i][j]=1;
                }
                else{
                    if(matrix[i][j]==1){
                        a[i][j]=a[i-1][j]+1;
                    }
                }
            }
        }
        int ans=0;
        sort(a.begin(), a.end());
        for(int i=0; i<a.size(); i++){
            sort(a[i].begin(), a[i].end());
            reverse(a[i].begin(), a[i].end());
            for(int j=0; j<a[i].size(); j++){
                ans=max(ans, (a[i][j]*(j+1)));
            }
        }
        return ans;
    }
};