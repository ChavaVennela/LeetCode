class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<int>>vals(m, vector<int>(n, INT_MAX));
        vals[0][0]=grid[0][0];
        pq.push({0,0,0});
        while(!pq.empty()){
            vector<int>temp=pq.top();
            pq.pop();
            int posi=temp[1], posj=temp[2];
            if(posi==m-1 && posj==n-1){
                return temp[0];
            }
            else{
                if(posi+1<m && temp[0]+grid[posi+1][posj]<vals[posi+1][posj]){
                    vals[posi+1][posj]=temp[0]+grid[posi+1][posj];
                    pq.push({vals[posi+1][posj], posi+1, posj});
                }
                if(posi-1>=0 && temp[0]+grid[posi-1][posj]<vals[posi-1][posj]){
                    vals[posi-1][posj]=temp[0]+grid[posi-1][posj];
                    pq.push({vals[posi-1][posj], posi-1, posj});
                }
                if(posj+1<n && temp[0]+grid[posi][posj+1]<vals[posi][posj+1]){
                    vals[posi][posj+1]=temp[0]+grid[posi][posj+1];
                    pq.push({vals[posi][posj+1], posi, posj+1});
                }
                if(posj-1>=0 && temp[0]+grid[posi][posj-1]<vals[posi][posj-1]){
                    vals[posi][posj-1]=temp[0]+grid[posi][posj-1];
                    pq.push({vals[posi][posj-1], posi, posj-1});
                }
            }
        }
        return vals[m-1][n-1];
    }
};