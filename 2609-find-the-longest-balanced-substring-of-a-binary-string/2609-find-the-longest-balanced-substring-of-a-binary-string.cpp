class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        stack<int>a;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                if(a.empty() || a.top()==0){
                    a.push(s[i]-'0');
                }
                else{
                    int temp=a.size();
                    int temp1=a.size();
                    while(!a.empty()){
                        if(a.top()==1){
                            temp1--;
                        }
                        a.pop();
                    }
                    ans=max(ans, min(temp1, temp-temp1));
                    a.push(s[i]-'0');
                }
            }
            else{
                if(a.empty()){
                    continue;
                }
                a.push(s[i]-'0');
            }
        }
        if(!a.empty()){
            int temp=a.size();
            int temp1=a.size();
            while(!a.empty()){
                if(a.top()==1){
                    temp1--;
                }
                a.pop();
            }
            ans=max(ans, min(temp1, temp-temp1));
        }
        return ans*2;
    }
};