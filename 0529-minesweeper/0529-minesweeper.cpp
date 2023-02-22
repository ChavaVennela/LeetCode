class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r=click[0], c=click[1], flag=0;
        if(r<0||c<0||r==board.size()||c==board[0].size()){
            return board;
        }
        if(board[r][c]=='M'){
            board[r][c]='X';
            return board;
        }
        if(board[r][c]=='E'){
            int count=0;
            if(r+1<board.size()||c+1<board[0].size()||r-1>=0||c-1>=0){
                flag=1;
                if(r+1<board.size()){
                    if(board[r+1][c]=='M'){
                        count++;
                    }
                    if(c-1>=0 && board[r+1][c-1]=='M'){
                        count++;
                    }
                    if(c+1<board[0].size() && board[r+1][c+1]=='M'){
                        count++;
                    }
                }
                if(c-1>=0 && board[r][c-1]=='M'){
                    count++;
                }
                if(c+1<board[0].size() && board[r][c+1]=='M'){
                    count++;
                }
                if(r-1>=0){
                    if(board[r-1][c]=='M'){
                        count++;
                    }
                    if(c-1>=0 && board[r-1][c-1]=='M'){
                        count++;
                    }
                    if(c+1<board[0].size() && board[r-1][c+1]=='M'){
                        count++;
                    }
                }
            }
            if(count!=0){
                board[r][c]=(char)('0'+count);
            }
            else{
                board[r][c]='B';
                if(flag==1){
                    vector<int>a{r-1,c};
                    vector<int>b{r-1, c-1};
                    vector<int>c1{r-1, c+1};
                    vector<int>d{r, c-1};
                    vector<int>e{r,c+1};
                    vector<int>f{r+1, c-1};
                    vector<int>g{r+1,c+1};
                    vector<int>h{r+1, c};
                    updateBoard(board, a);
                    updateBoard(board, b);
                    updateBoard(board, c1);
                    updateBoard(board, d);
                    updateBoard(board, e);
                    updateBoard(board, f);
                    updateBoard(board, g);
                    updateBoard(board, h);
                }
            }
        }
        return board;
    }
};