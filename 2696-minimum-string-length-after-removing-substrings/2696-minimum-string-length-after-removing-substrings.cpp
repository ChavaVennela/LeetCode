class Solution {
public:
    int minLength(string s) {
        vector<char>a;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='B'){
                if(a.size()>0 && a[a.size()-1]=='A'){
                    a.pop_back();
                }
                else{
                    a.push_back(s[i]);
                }
            }
            else if(s[i]=='D'){
                if(a.size()>0 && a[a.size()-1]=='C'){
                    a.pop_back();
                }
                else{
                    a.push_back(s[i]);
                }
            }
            else{
                a.push_back(s[i]);
            }
        }
        return a.size();
    }
};