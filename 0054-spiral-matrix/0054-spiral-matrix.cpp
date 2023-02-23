class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>>visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        int count=1, count1=0, balance=(matrix.size()*matrix[0].size()), i=0, j=0;
        vector<int>ans;
        while(balance>0){
            if(visited[i][j]==0){
                ans.push_back(matrix[i][j]);
                visited[i][j]=1;
                balance--;
            }
            if(count==0){
                if(count1==0){
                    if(i+1<matrix.size() && visited[i+1][j]==0){
                        i++;
                    }
                    else{
                        count=1;
                        count1=1;
                        if(j-1>=0 && visited[i][j-1]==0){
                            j--;
                        }
                    }
                }
                else{
                    if(i-1>=0 && visited[i-1][j]==0){
                        i--;
                    }
                    else{
                        count=1;
                        count1=0;
                        if(j+1<matrix[0].size() && visited[i][j+1]==0){
                            j++;
                        }
                    }
                }
            }
            else{
                if(count1==0){
                    if(j+1<matrix[0].size() && visited[i][j+1]==0){
                        j++;
                    }
                    else{
                        count=0;
                        if(i+1<matrix.size()){
                            i++;
                        }
                    }
                }
                else{
                    if(j-1>=0 && visited[i][j-1]==0){
                        j--;
                    }
                    else{
                        count=0;
                        if(i-1>=0 && visited[i-1][j]==0){
                            i--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};