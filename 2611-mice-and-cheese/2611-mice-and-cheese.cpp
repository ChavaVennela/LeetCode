class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int i, j=0, ans=0;
        vector<pair<int, int>>a;
        for(i=0; i<reward1.size(); i++){
            a.push_back({reward1[i]-reward2[i], i});
        }
        sort(a.begin(), a.end());
        for(i=a.size()-1; i>=0; i--){
            if(j<k){
                ans=ans+reward1[a[i].second];
                j++;
            }
            else{
                ans=ans+reward2[a[i].second];
            }
        }
        return ans;
    }
};