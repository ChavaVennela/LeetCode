class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int i;
        bool a1=true;
        vector<int>a{0, 0};
        for(i=0; i<bills.size(); i++){
            if(bills[i]==5){
                a[0]++;
            }
            else if(bills[i]==10){
                if(a[0]==0){
                    return false;
                }
                else{
                    a[0]--;
                    a[1]++;
                }
            }
            else{
                if((a[0]>=1 && a[1]>=1) ||(a[0]>=3)){
                    if(a[0]>=1 && a[1]>=1){
                        a[0]--;
                        a[1]--;
                    }
                    else{
                        a[0]=a[0]-3;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};