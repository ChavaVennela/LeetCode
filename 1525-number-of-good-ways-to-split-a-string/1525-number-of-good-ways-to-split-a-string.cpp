class Solution {
public:
    int numSplits(string s) {
        vector<int>a(26, 0);
        vector<int>b(26, 0);
        int count=0, count1=0, ans=0;
        for(int i=0; i<s.size(); i++){
            b[s[i]-'a']++;
            if(b[s[i]-'a']==1){
                count1++;
            }
        }
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a']++;
            if(a[s[i]-'a']==1){
                count++;
            }
            b[s[i]-'a']--;
            if(b[s[i]-'a']==0){
                count1--;
            }
            if(count==count1){
                ans++;
            }
        }
        return ans;
    }
};