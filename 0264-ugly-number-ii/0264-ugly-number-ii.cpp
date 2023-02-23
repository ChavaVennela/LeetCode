class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1){
            return 1;
        }
        vector<int>a(n);
        a[0]=1;
        int i, it2=0, it3=0, it5=0;
        for(i=1; i<n; i++){
            a[i]=min(a[it2]*2, min(a[it3]*3, a[it5]*5));
            if(a[i]==a[it2]*2){
                it2++;
            }
            if(a[i]==a[it3]*3){
                it3++;
            }
            if(a[i]==a[it5]*5){
                it5++;
            }
        }
        return a[n-1];
    }
};