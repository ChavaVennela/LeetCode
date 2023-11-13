class Solution {
public:
    bool check(char s){
        if(s=='a' || s=='A' || s=='e' || s=='E' || s=='i' || s=='I' || s=='o' || s=='O' || s=='u' || s=='U'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<char>s1;
        int i, j=0;
        for(i=0; i<s.size(); i++){
            if(check(s[i])){
                s1.push_back(s[i]);
            }
        }
        sort(s1.begin(), s1.end());
        for(i=0; i<s.size(); i++){
            if(check(s[i])){
                s[i]=s1[j];
                j++;
            }
        }
        return s;
    }
};