class Solution {
public:
    int compress(vector<char>& chars) {
        int len=chars.size(), i, temp=1;
        string s="";
        for(i=1; i<len; i++){
            if(chars[i]==chars[i-1]){
                temp++;
            }
            else{
                s=s+chars[i-1];
                if(temp>1){
                    s=s+to_string(temp);
                }
                temp=1;
            }
        }
        s=s+chars[i-1];
        if(temp>1){
            s=s+to_string(temp);
        }
        for(i=0; i<s.size(); i++){
            chars[i]=s[i];
        }
        return s.size();
    }
};