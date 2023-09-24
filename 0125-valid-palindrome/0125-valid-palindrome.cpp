class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                temp+=s[i];
            }
            else if(s[i]>='A' && s[i]<='Z'){
                temp+=(s[i]+32);
            }
            else if(s[i]>='0' && s[i]<='9'){
                temp+=s[i];
            }
        }
        string a=temp;
        reverse(a.begin(), a.end());
        if(a==temp){
            return true;
        }
        return false;
    }
};