class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            while(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) && i<j && i<s.size()){
                i++;
            }
            while(!((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9')) && i<j && j>=0){
                j--;
            }
            if((s[i]>='A' && s[i]<='Z')){
                s[i]=s[i]+32;
            }
            if((s[j]>='A' && s[j]<='Z')){
                s[j]=s[j]+32;
            }
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};