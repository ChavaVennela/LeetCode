class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int i;
        vector<int>ans;
        for(i=0; i<spells.size(); i++){
            long long val=ceil((1.0*success)/spells[i]);
            if(val>potions[potions.size()-1]){
                ans.push_back(0);
                continue;
            }
            int pos=lower_bound(potions.begin(), potions.end(), val)-potions.begin();
            ans.push_back(potions.size()-pos);
        }
        return ans;
    }
};