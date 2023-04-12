class Solution {
public:
    string simplifyPath(string path) {
        stack<char>a;
        int i;
        a.push('/');
        int count=0;
        for(i=0; i<path.size(); i++){
            if(a.top()=='/' && path[i]=='/'){
                continue;
            }
            if(path[i]=='/'){
                if(a.top()=='.'){
                    if(count==1){
                        a.pop();
                        a.pop();
                        count=0;
                        a.push(path[i]);
                    }
                    else if(count==2){
                        int temp=0;
                        count=0;
                        while(temp<2 && !a.empty()){
                            if(a.top()=='/'){
                                temp++;
                            }
                            a.pop();
                        }
                        a.push(path[i]);
                    }
                    else{
                        count=0;
                        a.push(path[i]);
                    }
                }
                else{
                    a.push(path[i]);
                }
            }
            else if(path[i]=='.'){
                if(count==0){
                    if(a.top()=='/'){
                        count++;
                        a.push(path[i]);
                    }
                    else{
                        a.push(path[i]);
                    }
                }
                else{
                    count++;
                    a.push(path[i]);
                }
            }
            else{
                if(count!=0){
                    count=0;
                }
                a.push(path[i]);
            }
        }
        if(count!=0){
            if(count==1){
                a.pop();
                a.pop();
            }
            else if(count==2){
                int temp=0;
                count=0;
                while(temp<2 && !a.empty()){
                    if(a.top()=='/'){
                        temp++;
                    }
                    a.pop();
                }
            }
        }
        if(!a.empty() && a.top()=='/'){
            a.pop();
        }
        if(a.empty()){
            return "/";
        }
        string ans="";
        while(!a.empty()){
            ans=ans+a.top();
            a.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};