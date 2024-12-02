class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int spaceCount=0, flag=1, idx=0;
        while(idx<sentence.size()){
            if(flag==1){
                if(sentence.substr(idx, searchWord.size())==searchWord){
                    return spaceCount+1;
                }
                else{
                    flag=0;
                }
            }
            else{
                if(sentence[idx]==' '){
                    spaceCount++;
                    flag=1;
                }
            }
            idx++;
        }
        return -1;
    }
};