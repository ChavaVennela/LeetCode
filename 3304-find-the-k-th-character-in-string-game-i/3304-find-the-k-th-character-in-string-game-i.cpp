class Solution {
public:
    char kthCharacter(int k) {
        int num=ceil(log2(k));
        string word="a";
        string last="";
        for(int i=0; i<num; i++){
            if(last==""){
                last="b";
            }
            else{
                string temp=last;
                for(int j=0; j<last.size(); j++){
                    char temp1;
                    if(last[j]=='z'){
                        temp1='a';
                    }
                    else{
                        temp1=last[j]+1;
                    }
                    temp+=temp1;
                }
                last =temp;
            }
            word+=last;
        }
        return word[k-1];
    }
};