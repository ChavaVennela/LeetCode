class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        if(needle.size()>haystack.size()){
            return -1;
        }
        if(needle.size()==haystack.size()){
            if(needle==haystack){
                return 0;
            }
            return -1;
        }
        for(i=0; i<haystack.size(); i++){
            if(haystack[i] == needle[0] && i+needle.size()<=haystack.size()){
                if(needle==haystack.substr(i, needle.size())){
                    return i;
                }
            }
        }
        return -1;
    }
};