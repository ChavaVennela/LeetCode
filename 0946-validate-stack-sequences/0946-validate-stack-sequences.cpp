class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i, j=0;
        stack<int>s;
        for(i=0; i<pushed.size(); i++){
            s.push(pushed[i]);
            while(!s.empty() && s.top()==popped[j] && j<popped.size()){
                s.pop();
                j++;
            }
        }
        if(j==popped.size()){
            return true;
        }
        return false;
    }
};