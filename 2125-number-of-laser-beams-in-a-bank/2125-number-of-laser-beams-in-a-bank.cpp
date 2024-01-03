class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int curr=0, prev=0, ans=0;
        for(int i=0; i<bank.size(); i++){
            int temp=0;
            for(int j=0; j<bank[i].size(); j++){
                if(bank[i][j]=='1'){
                    temp++;
                }
            }
            if(temp>0){
                if(curr>0){
                    if(prev>0){
                        ans+=(curr*prev);
                        prev=curr;
                        curr=temp;
                    }
                    else{
                        prev=curr;
                        curr=temp;
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
        if(curr>0 && prev>0){
            ans+=(curr*prev);
        }
        return ans;
    }
};