class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end());
        if(s[0]=='1' || s[s.size()-1]=='0'){
            return s;
        }
        if(s[s.size()-1]=='1'){
            s[0]='1';
            
        }
        for(int i=1; i<s.size(); i++){
            if(s[i]=='1'){
                s[i]='0';
                break;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};