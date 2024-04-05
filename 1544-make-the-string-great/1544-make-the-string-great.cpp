class Solution {
public:
    string makeGood(string s) {
        stack<char>a;
        for(int i=0; i<s.size(); i++){
            if(a.empty()){
                a.push(s[i]);
            }
            else if(s[i]>='a' && s[i]<='z'){
                if(a.top()>='A' && a.top()<='Z'){
                    if(s[i]-'a'==a.top()-'A'){
                        a.pop();
                    }
                    else{
                        a.push(s[i]);
                    }
                }
                else{
                    a.push(s[i]);
                }
            }
            else{
                if(a.top()>='a' && a.top()<='z'){
                    if(s[i]-'A'==a.top()-'a'){
                        a.pop();
                    }
                    else{
                        a.push(s[i]);
                    }
                }
                else{
                    a.push(s[i]);
                }
            }
        }
        string ans="";
        while(!a.empty()){
            ans+=a.top();
            a.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};