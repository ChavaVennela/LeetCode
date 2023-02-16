class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>>a;
        vector<vector<string>>ans;
        int i;
        for(i=0; i<strs.size(); i++){
            string s=strs[i];
            sort(s.begin(), s.end());
            a.push_back({s, i});
        }
        sort(a.begin(), a.end());
        for(i=0; i<a.size(); i++){
            vector<string>b;
            if(i==0){
                b.push_back(strs[a[i].second]);
                ans.push_back(b);
            }
            else{
                if(a[i].first==a[i-1].first){
                    ans[ans.size()-1].push_back(strs[a[i].second]);
                }
                else{
                    b.push_back(strs[a[i].second]);
                    ans.push_back(b);
                }
            }
        }
        return ans;
    }
};