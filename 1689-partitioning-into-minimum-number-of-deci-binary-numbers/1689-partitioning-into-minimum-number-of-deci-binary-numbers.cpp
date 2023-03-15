class Solution {
public:
    int minPartitions(string n) {
        int ans=0, i;
        for(i=0; i<n.size(); i++){
            ans=max(ans, n[i]-'0');
        }
        return ans;
    }
};