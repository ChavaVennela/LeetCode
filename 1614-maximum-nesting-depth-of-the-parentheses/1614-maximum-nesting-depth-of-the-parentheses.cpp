class Solution {
public:
    int maxDepth(string s) {
        stack<char>a;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                a.push(s[i]);
                ans=max(ans, (int)a.size());
            }
            else if(s[i]==')'){
                a.pop();
            }
        }
        return ans;
    }
};