class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int>a;
        for(int i=0; i<ransomNote.size(); i++){
            a[ransomNote[i]]++;
        }
        for(int i=0; i<magazine.size(); i++){
            if(a.find(magazine[i])!=a.end()){
                a[magazine[i]]--;
            }
        }
        for(auto it=a.begin(); it!=a.end(); it++){
            if(it->second>0){
                return false;
            }
        }
        return true;
    }
};