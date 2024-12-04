class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.size()>str1.size()){
            return false;
        }
        int i=0, j=0;
        while(i<str2.size() && j<str1.size()){
            if(str1[j]==str2[i]){
                i++;
            }
            else if(((str1[j]-'a')+26+1)%26==str2[i]-'a'){
                i++;
            }
            j++;
        }
        if(i==str2.size()){
            return true;
        }
        return false;
    }
};