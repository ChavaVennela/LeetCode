class Solution {
public:
    long long minimumSteps(string s) {
        stack<int>a;
        long long ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                a.push(1);
            }
            else{
                if(!a.empty()){
                    a.push(0);
                }
            }
        }
        while(!a.empty() && a.top()==1){
            a.pop();
        }
        long long temp=0;
        while(!a.empty()){
            if(a.top()==0){
                temp++;
            }
            else{
                ans+=temp;
            }
            a.pop();
        }
        return ans;
    }
};