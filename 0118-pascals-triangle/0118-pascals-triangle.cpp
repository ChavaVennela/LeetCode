class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i, j;
        vector<vector<int>>a;
        for(i=0; i<numRows; i++){
            vector<int>b;
            b.push_back(1);
            if(i>1){
                for(j=1; j<a[i-1].size(); j++){
                    b.push_back(a[i-1][j-1] + a[i-1][j]);
                }
            }
            if(i>0){
                b.push_back(1);
            }
            a.push_back(b);
        }
        return a;
    }
};