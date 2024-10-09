class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>a;
        for(int i=0; i<s.size(); i++){
            if(s[i]==')' && !a.empty()){
                if(a.top()=='('){
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
        return a.size();
    }
};