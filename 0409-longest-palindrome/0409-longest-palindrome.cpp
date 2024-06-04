class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>a;
        for(int i=0; i<s.size(); i++){
            a[s[i]]++;
        }
        int odd=0, count=0;
        for(auto it=a.begin(); it!=a.end(); it++){
            if(it->second%2==0){
                count+=it->second;
            }
            else{
                count+=it->second-1;
                odd=1;
            }
        }
        return odd+count;
    }
};