class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>a(26, 0);
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                a[words[i][j]-'a']++;
            }
        }
        for(int i=0; i<26; i++){
            if(a[i]!=0 && a[i]%words.size()!=0){
                return false;
            }
        }
        return true;
    }
};