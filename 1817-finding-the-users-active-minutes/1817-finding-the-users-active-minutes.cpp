class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>>a;
        unordered_map<int, int>count;
        for(int i=0; i<logs.size(); i++){
            a[logs[i][0]].insert(logs[i][1]);
        }
        for(auto it=a.begin(); it!=a.end(); it++){
            count[it->second.size()]++;
        }
        vector<int>ans;
        for(int i=0; i<k; i++){
            if(count.find(i+1)!=count.end()){
                ans.push_back(count[i+1]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};