class Solution {
public:
    int totalMoney(int n) {
        int ini=1, ans=0, temp=1;
        for(int i=0; i<n; i++){
            if(i!=0 && i%7==0){
                temp=ini+1;
                ini++;
            }
            ans+=temp;
            temp++;
        }
        return ans;
    }
};