class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>>ans;
        for(int i=0; i<box.size(); i++){
            stack<char>s;
            for(int j=box[0].size()-1; j>=0; j--){
                if(box[i][j]=='.'){
                    s.push(box[i][j]);
                }
                else if(box[i][j]=='*'){
                    s=stack<char>();
                }
                else{
                    if(!s.empty()){
                        int count=s.size();
                        box[i][j+count]='#';
                        box[i][j]='.';
                    }
                }
            }
        }
        for(int i=0; i<box[0].size(); i++){
            vector<char>temp;
            for(int j=box.size()-1; j>=0; j--){
                temp.push_back(box[j][i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};