class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, count=0;
        for(i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(i+1 <s.size() && s[i+1] != ' '){
                    count=0;
                }
            }
            else{
                count++;
            }
        }
        return count;
    }
};