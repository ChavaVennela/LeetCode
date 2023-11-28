class Solution {
public:
    int numberOfWays(string corridor) {
        int seats=0;
        long ans=1, sc=0, pc=0;
        for(int i=0; i<corridor.size(); i++){
            if(corridor[i]=='S'){
                seats++;
            }
        }
        if(seats%2!=0 || seats==0){
            return 0;
        }
        int i=0;
        while(i<corridor.size()){
            while(i<corridor.size() && sc!=2){
                if(corridor[i]=='S'){
                    sc++;
                }
                i++;
            }
            while(i<corridor.size() && corridor[i]!='S'){
                pc++;
                i++;
            }
            if(i==corridor.size()){
                continue;
            }
            ans=(ans*(pc+1))%1000000007;
            sc=1;
            pc=0;
            i++;
        }
        return ans;
    }
};