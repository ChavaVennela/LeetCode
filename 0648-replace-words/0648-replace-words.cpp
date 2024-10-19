class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int>a;
        for(int i=0; i<dictionary.size(); i++){
            a[dictionary[i]]++;
        }
        string ans="";
        int flag=0;
        string temp="";
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i]==' '){
                if(temp!=""){
                    ans+=' ';
                    temp="";
                    flag=0;
                }
            }
            else{
                if(flag==1){
                    continue;
                }
                else{
                    ans+=sentence[i];
                    temp+=sentence[i];
                    if(a.count(temp)!=0){
                        flag=1;
                    }
                }
            }
        }
        return ans;
    }
};