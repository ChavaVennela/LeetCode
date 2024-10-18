class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string s1=s;
        sort(s1.begin(), s1.end());
        reverse(s1.begin(), s1.end());
        char temp='a';
        for(int i=0; i<s.size(); i++){
            if(s1[i]!=s[i]){
                temp=s[i];
                s[i]=s1[i];
                for(int j=s.size()-1; j>=0; j--){
                    if(s[j]==s[i]){
                        s[j]=temp;
                        break;
                    }
                }
                return stoi(s);
            }
        }
        return num;
    }
};