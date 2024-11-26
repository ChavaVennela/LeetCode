class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>a(n, 0);
        for(int i=0; i<edges.size(); i++){
            a[edges[i][1]]++;
        }
        int ans=n+1;
        for(int i=0; i<a.size(); i++){
            if(a[i]==0){
                if(ans==n+1){
                    ans=i;
                }
                else{
                    return -1;
                }
            }
        }
        return ans;
    }
};