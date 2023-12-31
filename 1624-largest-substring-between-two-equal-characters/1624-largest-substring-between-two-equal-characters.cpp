class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<int, vector<int>>a;
        int ans=-1;
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a'].push_back(i);
        }
        for(auto i=a.begin(); i!=a.end(); i++){
            if(i->second.size()>1){
                vector<int>temp=i->second;
                ans=max(ans, temp[temp.size()-1]-temp[0]-1);
            }
        }
        return ans;
    }
};