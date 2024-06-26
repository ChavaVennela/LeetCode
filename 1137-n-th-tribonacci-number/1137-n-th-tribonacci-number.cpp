class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1 || n==2){
            return 1;
        }
        int a=0, b=1, c=1, i, ans=0;
        for(i=2; i<n; i++){
            ans=a+b+c;
            a=b;
            b=c;
            c=ans;
        }
        return ans;
    }
};