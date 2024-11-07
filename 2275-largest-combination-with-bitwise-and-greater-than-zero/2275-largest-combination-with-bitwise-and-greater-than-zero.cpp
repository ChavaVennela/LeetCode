class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>a(24, 0);
        for(int i=0; i<candidates.size(); i++){
            string temp=bitset<24>(candidates[i]).to_string();
            for(int j=0; j<temp.size(); j++){
                if(temp[j]=='1'){
                    a[j]++;
                }
            }
        }
        int maxval=0;
        for(int i=0; i<a.size(); i++){
            maxval=max(maxval, a[i]);
        }
        return maxval;
    }
};