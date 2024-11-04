class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int i=0;
        while(i<word.size()){
            int count=0;
            char curr=word[i];
            while(i<word.size() && count<9 && curr==word[i]){
                count++;
                i++;
            }
            ans+=to_string(count)+curr;
        }
        return ans;
    }
};