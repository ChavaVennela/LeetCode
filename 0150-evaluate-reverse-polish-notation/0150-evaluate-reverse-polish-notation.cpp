class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<pair<string, int>>a;
        for(int i=tokens.size()-1; i>=0; i--){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                a.push({tokens[i], 0});
            }
            else{
                if(a.empty()){
                    a.push({tokens[i], 0});
                }
                else{
                    a.push({tokens[i], a.top().second+1});
                }
                while(a.top().second==2){
                    int val1=stoi(a.top().first);
                    a.pop();
                    int val2=stoi(a.top().first);
                    a.pop();
                    string op=a.top().first;
                    a.pop();
                    int res;
                    if(op=="+"){
                        res=val1+val2;
                    }
                    else if(op=="-"){
                        res=val1-val2;
                    }
                    else if(op=="*"){
                        res=val1*val2;
                    }
                    else if(op=="/"){
                        res=val1/val2;
                    }
                    string res1=to_string(res);
                    if(a.empty()){
                        a.push({res1, 0});
                    }
                    else{
                        a.push({res1, a.top().second+1});
                    }
                }
            }
        }
        return stoi(a.top().first);
    }
};