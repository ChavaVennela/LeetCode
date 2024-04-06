class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        stack<char>a;
        for(int i=0; i<s.size(); i++){
            if(a.empty() && s[i]!='('){
                ans+=s[i];
            }
            else if(s[i]!=')'){
                a.push(s[i]);
            }
            else{
                string temp="";
                while(a.top()!='('){
                    temp+=a.top();
                    a.pop();
                }
                a.pop();
                if(a.empty()){
                    ans+=temp;
                }
                else{
                    for(int j=0; j<temp.size(); j++){
                        a.push(temp[j]);
                    }
                }
            }
        }
        return ans;
    }
};