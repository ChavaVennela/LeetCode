class Solution {
public:
    int minSwaps(string s) {
        stack<int>a;
        for(int i=0; i<s.size(); i++){
            if(a.size()==0){
                a.push(s[i]);
            }
            else if(a.top()==s[i]){
                a.push(s[i]);
            }
            else{
                if(a.top()==']'){
                    a.push(s[i]);
                }
                else{
                    a.pop();
                }
            }
        }
        if(a.size()==0){
            return 0;
        }
        return ceil((double)a.size()/4);
    }
};