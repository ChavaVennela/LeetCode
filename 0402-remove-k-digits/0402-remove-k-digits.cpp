class Solution {
public:
    string removeKdigits(string num, int k) {
        string temp="";
        for(int i=0; i<num.size(); i++){
            while(temp.size()>0 && k>0 && temp.back()>num[i]){
                temp.pop_back();
                k--;
            }
            temp+=num[i];
        }
        while(k>0 && temp.size()>0){
            temp.pop_back();
            k--;
        }
        int pos=-1;
        for(int i=0; i<temp.size(); i++){
            if(temp[i]!='0'){
                pos=i;
                break;
            }
        }
        if(pos==-1){
            return "0";
        }
        else{
            return temp.substr(pos);
        }
    }
};