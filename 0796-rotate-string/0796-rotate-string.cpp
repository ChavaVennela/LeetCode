class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string sample=s+s;
        if(sample.find(goal)<sample.size()){
            return true;
        }
        return false;
    }
};