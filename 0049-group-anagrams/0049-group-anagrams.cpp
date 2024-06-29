class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>>my_map;
        for(int i=0; i<strs.size(); i++){
            string a=strs[i];
            sort(a.begin(), a.end());
            my_map[a].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it=my_map.begin(); it!=my_map.end(); it++){
            vector<string>temp1;
            for(int i=0; i<it->second.size(); i++){
                temp1.push_back(strs[it->second[i]]);
            }
            ans.push_back(temp1);
        }
        return ans;
    }
};