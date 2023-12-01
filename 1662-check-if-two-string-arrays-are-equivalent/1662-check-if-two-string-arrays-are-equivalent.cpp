class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i;
        string s="", s1="";
        for(i=0; i<word1.size(); i++){
            s=s+word1[i];
        }
        for(i=0; i<word2.size(); i++){
            s1=s1+word2[i];
        }
        return s==s1;
    }
};