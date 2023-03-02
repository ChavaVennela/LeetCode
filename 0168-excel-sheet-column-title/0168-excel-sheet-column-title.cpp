class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        if(columnNumber==0){
            return s;
        }
        if(columnNumber<=26){
            s="A";
            s[0]=s[0]+(columnNumber-1);
            return s;
        }
        if(columnNumber%26==0){
            s=s+convertToTitle((columnNumber-1)/26)+convertToTitle(26);
        }
        else{
            s=s+convertToTitle(columnNumber/26)+convertToTitle(columnNumber%26);
        }
        return s;
    }
};