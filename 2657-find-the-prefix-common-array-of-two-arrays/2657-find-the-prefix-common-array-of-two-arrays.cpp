class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>a(A.size(),0);
        vector<int>b(A.size(),0);
        for(int i=0; i<A.size(); i++){
            if(A[i]==B[i]){
                if(i==0){
                    b[i]=1;
                }
                else{
                    b[i]=b[i-1]+1;
                }
            }
            else{
                int count=0;
                a[A[i]-1]++;
                a[B[i]-1]++;
                if(a[A[i]-1]%2==0){
                    count++;
                }
                if(a[B[i]-1]%2==0){
                    count++;
                }
                if(i==0){
                    b[i]=count;
                }
                else{
                    b[i]=b[i-1]+count;
                }
            }
        }
        return b;
    }
};