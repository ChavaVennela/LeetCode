class Solution {
public:
    int minimumLength(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                char a=s[i];
                while((s[i]==a || s[j]==a) && i<=j){
                    if(i==j){
                        j--;
                        break;
                    }
                    if(s[i]==a){
                        i++;
                    }
                    if(s[j]==a){
                        j--;
                    }
                }
            }
            else{
                break;
            }
        }
        return j-i+1;
    }
};