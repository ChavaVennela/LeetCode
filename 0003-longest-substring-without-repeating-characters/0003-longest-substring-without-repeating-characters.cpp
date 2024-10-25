class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>a;
        int j=0, ans=0, crr=0;
        for(int i=0; i<s.size(); i++){
            if(a[s[i]]+1>1){
                while(a[s[i]]+1>1){
                    a[s[j]]--;
                    crr--;
                    j++;
                }
            }
            a[s[i]]++;
            crr++;
            ans=max(crr, ans);
        }
        return ans;
    }
};