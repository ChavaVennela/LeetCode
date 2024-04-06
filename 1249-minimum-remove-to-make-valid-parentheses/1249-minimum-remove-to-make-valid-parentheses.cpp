class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>a;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                continue;
            }
            else{
                if(a.empty()){
                    if(s[i]=='('){
                        a.push(i);
                    }
                }
                else if(s[i]=='('){
                    a.push(i);
                }
                else{
                    s[a.top()]='1';
                    s[i]='0';
                    a.pop();
                }
            }
        }
        string ans="";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                ans+=')';
            }
            else if(s[i]=='1'){
                ans+='(';
            }
            else if(s[i]>='a' && s[i]<='z'){
                ans+=s[i];
            }
        }
        return ans;
    }
};