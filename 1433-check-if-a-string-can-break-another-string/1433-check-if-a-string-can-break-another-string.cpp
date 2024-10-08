class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int count=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]>=s2[i]){
                continue;
            }
            else{
                count=1;
                break;
            }
        }
        if(count==1){
            for(int i=0; i<s1.size(); i++){
                if(s1[i]<=s2[i]){
                    continue;
                }
                else{
                    count=2;
                    break;
                }
            }
            if(count==2){
                return false;
            }
            return true;
        }
        return true;
    }
};