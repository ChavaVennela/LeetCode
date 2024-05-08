class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>ans;
        vector<int>dup;
        for(int i=0; i<score.size(); i++){
            dup.push_back(score[i]);
        }
        sort(dup.begin(), dup.end());
        unordered_map<int, string>a;
        int count=0;
        for(int i=dup.size()-1; i>=0; i--){
            if(count<3){
                if(count==0){
                    a[dup[i]]="Gold Medal";
                }
                else if(count==1){
                    a[dup[i]]="Silver Medal";
                }
                else{
                    a[dup[i]]="Bronze Medal";
                }
            }
            else{
                a[dup[i]]=to_string(count+1);
            }
            count++;
        }
        for(int i=0; i<score.size(); i++){
            ans.push_back(a[score[i]]);
        }
        return ans;
    }
};