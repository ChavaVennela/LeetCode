class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        long long count=0, i;
        vector<long long> a(high+1, 0);
        a[0]=1;
        for(i=1; i<=high; i++){
            if(i-zero>=0){
                a[i]+=(a[i-zero])%(long long)(pow(10, 9)+7);
            }
            if(i-one>=0){
                a[i]+=(a[i-one])%(long long)(pow(10, 9)+7);
            }
            if(i>=low){
                count=(count+a[i])%(long long)(pow(10, 9)+7);
            }
            
        }
        return count;
    }
};