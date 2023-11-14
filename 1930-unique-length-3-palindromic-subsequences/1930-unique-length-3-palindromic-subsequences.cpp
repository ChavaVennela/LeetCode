class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>a(26, INT_MAX);
        vector<int>b(26, INT_MIN);
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a']=min(a[s[i]-'a'], i);
            b[s[i]-'a']=max(b[s[i]-'a'], i);
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(a[i]==INT_MAX ||b[i]==INT_MIN){
                continue;
            }
            unordered_set<char>temp;
            for(int j=a[i]+1; j<b[i]; j++){
                temp.insert(s[j]);
            }
            ans+=temp.size();
        }
        return ans;
    }
};