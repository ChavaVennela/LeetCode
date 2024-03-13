class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1; i<=n; i++){
            int temp=(i*(i+1))/2;
            if(temp == ((n*(n+1))/2)-temp+i){
                return i;
            }
        }
        return -1;
    }
};