class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string>a;
        map<string, char>b;
        vector<string>s1;
        string temp="";
        for(int i=0; i<s.size(); i++){
            if(s[i]==' ' && temp.size()>0){
                s1.push_back(temp);
                temp="";
            }
            else if(s[i]!=' '){
                temp+=s[i];
            }
        }
        if(temp.size()>0){
            s1.push_back(temp);
        }
        if(s1.size() != pattern.size()){
            return false;
        }
        for(int i=0; i<pattern.size(); i++){
            if(a.find(pattern[i])!=a.end()){
                if(a[pattern[i]]!=s1[i]){
                    return false;
                }
            }
            else if(b.find(s1[i])!=b.end()){
                if(b[s1[i]]!=pattern[i]){
                    return false;
                }
            }
            else{
                a[pattern[i]]=s1[i];
                b[s1[i]]=pattern[i];
            }
        }
        return true;
    }
};