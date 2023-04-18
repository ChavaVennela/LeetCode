class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int>ans;
        int i;
        for(i=0; i<s.size(); i++){
            int count=0, j=i, posi=startPos[0],posj=startPos[1];
            while(j<s.size() && posi<n && posj<n && posi>=0 && posj>=0){
                if(s[j]=='R'){
                    posj++;
                }
                else if(s[j]=='L'){
                    posj--;
                }
                else if(s[j]=='D'){
                    posi++;
                }
                else{
                    posi--;
                }
                if(posi<n && posj<n && posi>=0 && posj>=0){
                    count++;
                }
                j++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};