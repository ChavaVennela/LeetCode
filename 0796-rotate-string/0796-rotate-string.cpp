class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size() !=s.size()){
            return false;
        }
        vector<int>a;
        for(int i=0; i<s.size(); i++){
            if(s[i]==goal[0]){
                a.push_back(i);
            }
        }
        for(int i=0; i<a.size(); i++){
            bool found=true;
            int pos=a[i];
            for(int j=0; j<goal.size(); j++){
                if(s[pos]!=goal[j]){
                    found=false;
                    break;
                }
                else{
                    pos=(pos+1)%(s.size());
                }
            }
            if(found){
                return true;
            }
        }
        return false;
    }
};