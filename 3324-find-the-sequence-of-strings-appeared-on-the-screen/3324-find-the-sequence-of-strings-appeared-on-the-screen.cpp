class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        string temp="";
        for(int i=0; i<target.size(); i++){
            if(temp.size()==i){
                temp+='a';
                ans.push_back(temp);
            }
            while(temp[i]!=target[i]){
                temp[i]=(temp[i]+1);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};