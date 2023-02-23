class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s, mins;
        s = "";
        int min, i, j, count=0;
        j=0;
        min = strs[0].size();
        for(i=0; i<strs.size(); i++){
            if(strs[i].size() < min){
                min = strs[i].size();
            }
        }
        for(j=0; j<min; j++){
            for(i=1; i<strs.size(); i++){
                if(strs[i][j] != strs[i-1][j]){
                    count = 1;
                    break;
                }
            }
            if(count == 0){
                s = s + strs[0][j];
            }
            else{
                break;
            }
        }
        return s;
    }
};