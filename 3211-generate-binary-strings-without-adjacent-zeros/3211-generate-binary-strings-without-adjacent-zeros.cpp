class Solution {
public:
    vector<string>ans;
    int size;
    void gen(string temp){
        if(temp.size()==size){
            ans.push_back(temp);
            return;
        }
        if(temp==""){
            gen("1");
            gen("0");
        }
        else{
            if(temp[temp.size()-1]=='0'){
                string temp1=temp;
                temp1+="1";
                gen(temp1);
            }
            else{
                string temp1=temp+"1";
                string temp2=temp+"0";
                gen(temp1);
                gen(temp2);
            }
        }
        return;
    }
    vector<string> validStrings(int n) {
        size=n;
        gen("");
        return ans;
    }
};