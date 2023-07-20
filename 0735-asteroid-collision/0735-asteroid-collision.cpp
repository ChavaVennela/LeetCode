class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>a;
        int i;
        vector<int>ans1;
        for(i=0; i<asteroids.size(); i++){
            if(a.size()==0){
                if(asteroids[i]<0){
                    ans1.push_back(asteroids[i]);
                }
                else{
                    a.push(asteroids[i]);
                }
            }
            else{
                if(a.top()*asteroids[i]>0){
                    a.push(asteroids[i]);
                }
                else{
                    int count=0;
                    while(!a.empty() && a.top()*asteroids[i]<0){
                        if(abs(a.top())>abs(asteroids[i])){
                            count=1;
                            break;
                        }
                        else if(abs(a.top())<abs(asteroids[i])){
                            a.pop();
                        }
                        else{
                            a.pop();
                            count=1;
                            break;
                        }
                    }
                    if(count==0){
                        if(a.empty() && asteroids[i]<0){
                            ans1.push_back(asteroids[i]);
                        }
                        else{
                            a.push(asteroids[i]);
                        }
                    }
                }
            }
        }
        vector<int>ans;
        while(!a.empty()){
            ans.push_back(a.top());
            a.pop();
        }
        reverse(ans.begin(), ans.end());
        for(i=0; i<ans.size(); i++){
            ans1.push_back(ans[i]);
        }
        return ans1;
    }
};