class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int count=0;
        for(int i=s.size()-1; i>=0; i--){
            count=(count+(shifts[i])%26)%26;
            s[i]='a'+(((s[i]-'a')+count)%26);
        }
        return s;
    }
};