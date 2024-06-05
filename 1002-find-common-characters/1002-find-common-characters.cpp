class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, vector<int>>a;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                if(a.find(words[i][j])==a.end()){
                    for(int k=0; k<=i; k++){
                        a[words[i][j]].push_back(0);
                    }
                    a[words[i][j]][i]++;
                }
                else{
                    while(a[words[i][j]].size()<=i){
                        a[words[i][j]].push_back(0);
                    }
                    a[words[i][j]][i]++;
                }
            }
        }
        vector<string>ans;
        for(auto it=a.begin(); it!=a.end(); it++){
            if(it->second.size()==words.size()){
                sort(it->second.begin(), it->second.end());
                for(int i=0; i<it->second[0]; i++){
                    string b="";
                    b+=it->first;
                    ans.push_back(b);
                }
            }
        }
        return ans;
    }
};