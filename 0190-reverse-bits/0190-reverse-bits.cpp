class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s = bitset<32>(n).to_string();
        // reverse(s.begin(), s.end());
        uint32_t ans=0;
        for(int i=0; i<s.size(); i++){
            ans+=pow(2, i)*(s[i]-'0');
        }
        return ans;
    }
};