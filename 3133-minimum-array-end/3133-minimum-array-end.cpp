class Solution {
public:
    long long minEnd(int n, int x) {
        long long val=x;
        for(int i=1; i<n; i++){
            val=(val+1)|x;
        }
        return val;
    }
};