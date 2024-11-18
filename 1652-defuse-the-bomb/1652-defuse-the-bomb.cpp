class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(), 0);
        if(k==0){
            return ans;
        }
        else if(k>0){
            for(int i=0; i<code.size(); i++){
                int p=i+1, temp=0;
                for(int j=0; j<k; j++){
                    temp+=code[(p+j)%code.size()];
                }
                ans[i]=temp;
            }
        }
        else{
            for(int i=0; i<code.size(); i++){
                int p=i-1, temp=0;
                for(int j=0; j<abs(k); j++){
                    temp+=code[(code.size()+p-j)%code.size()];
                }
                ans[i]=temp;
            }
        }
        return ans;
    }
};