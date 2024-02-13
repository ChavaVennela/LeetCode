class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>a;
        for(int i=1; i<=m; i++){
            a.push_back(i);
        }
        vector<int>ans;
        for(int i=0; i<queries.size(); i++){
            for(int j=0; j<a.size(); j++){
                if(a[j]==queries[i]){
                    ans.push_back(j);
                    a.erase(a.begin()+j);
                    a.insert(a.begin(),queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};