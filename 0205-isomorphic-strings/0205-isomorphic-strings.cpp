class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char>a;
        map<char, int>b;
        for(int i=0; i<s.size(); i++){
            if(a.find(s[i])!=a.end()){
                if(a[s[i]]!=t[i]){
                    return false;
                }
            }
            else if(b.find(t[i])!=b.end()){
                if(b[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
                a[s[i]]=t[i];
                b[t[i]]=s[i];
            }
        }
        return true;
    }
};