class Solution {
public:
    bool find(int i, int j, int count, vector<vector<char>>&b, string s){
        if(count==s.size()){
            return true;
        }
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || b[i][j] != s[count]){
            return false;
        }
        int p, x;
        char temp=b[i][j];
        b[i][j]='*';
        bool check= find(i+1, j, count+1, b, s) || find(i-1, j, count+1, b, s) || find(i, j+1, count+1, b, s) || find(i, j-1, count+1, b, s);
        b[i][j]=temp;
        return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int i, j;
        for(i=0; i<board.size(); i++){
            for(j=0; j<board[i].size(); j++){
                if(board[i][j]==word[0]){
                    if(find(i, j, 0, board, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};