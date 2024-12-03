class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        for(int i=0; i<spaces.size(); i++){
            if(i==0){
                ans+=s.substr(0, spaces[i]);
                ans+=' ';
            }
            else{
                ans+=s.substr(spaces[i-1], spaces[i]-spaces[i-1]);
                ans+=' ';
            }
        }
        ans=ans+s.substr(spaces[spaces.size()-1]);
        return ans;
    }
};