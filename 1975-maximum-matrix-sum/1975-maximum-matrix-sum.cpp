class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0, minval=INT_MAX, count=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]<0){
                    count++;
                }
                minval=min(minval, (long long)abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
            }
        }
        if(count%2!=0){
            ans-=(2*(minval));
        }
        return ans;
    }
};