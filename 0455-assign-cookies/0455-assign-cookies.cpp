class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0, i=0, j=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(j<g.size() && i<s.size()){
            if(s[i]>=g[j]){
                count++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};