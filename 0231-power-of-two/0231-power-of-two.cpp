class Solution {
public:
    bool isPowerOfTwo(int n) {
        string s =bitset<64>(n).to_string();
        sort(s.begin(), s.end());
        if(s[s.size()-2] == '1' || s[s.size()-1] == '0'){
            return false;
        }
        return true;
    }
};