class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<pair<char, int>>a;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                a.push({'(', 0});
            }
            else{
                int temp=0;
                while(a.top().first != '('){
                    temp+=a.top().second;
                    a.pop();
                }
                a.pop();
                if(temp==0){
                    temp=1;
                }
                else{
                    temp=temp*2;
                }
                if(a.empty()){
                    ans+=temp;
                }
                else{
                    a.push({'*', temp});
                }
            }
        }
        return ans;
    }
};