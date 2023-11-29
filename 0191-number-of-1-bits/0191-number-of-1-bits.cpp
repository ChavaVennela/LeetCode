class Solution {
public:
    int hammingWeight(uint32_t n) {
        string s;
        s=bitset<32>(n).to_string();
        int count=0, i;
        for(i=0; i<s.size(); i++){
            if(s[i]=='1'){
                count++;
            }
        }
        return count;
    }
};