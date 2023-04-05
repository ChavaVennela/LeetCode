class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int>check;
        int i, j;
        for(i=0; i<s.size(); i++){
            int temp=chars.find(s[i]);
            if(temp<chars.size()){
                check.push_back(vals[temp]);
            }
            else{
                check.push_back(s[i]-'a'+1);
            }
        }
        int currsum=0, maxsum=0;
        for(i=0; i<check.size(); i++){
            currsum+=check[i];
            if(maxsum<currsum){
                maxsum=currsum;
            }
            if(currsum<0){
                currsum=0;
            }
        }
        return maxsum;
    }
};