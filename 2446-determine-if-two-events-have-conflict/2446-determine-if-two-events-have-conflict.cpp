class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<vector<string>>a;
        a.push_back(event1);
        a.push_back(event2);
        sort(a.begin(), a.end());
        if(a[0][1]>=a[1][0]){
            return true;
        }
        return false;
    }
};