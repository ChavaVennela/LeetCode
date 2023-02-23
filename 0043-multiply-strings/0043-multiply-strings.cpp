class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        vector<int>a(num1.size()+num2.size(), 0);
        string ans="";
        int i, j, count=0, carry=0, st=0, it=0;
        for(i=num1.size()-1; i>=0; i--){
            it=st;
            for(j=num2.size()-1; j>=0; j--){
                int temp1=(num1[i]-'0')*(num2[j]-'0');
                int temp2;
                if(a[it]+temp1>9){
                    temp2=a[it]+temp1;
                    a[it+1]+=temp2/10;
                    a[it]=temp2%10;
                }
                else{
                    a[it]+=temp1;
                }
                it++;
            }
            st++;
        }
        for(i=a.size()-1; i>=0; i--){
            ans=ans+to_string(a[i]);
        }
        string ans1="";
        count=0;
        for(i=0; i<ans.size(); i++){
            if(count==0){
                if(ans[i]=='0'){
                    continue;
                }
                else{
                    ans1=ans1+ans[i];
                    count=1;
                }
            }
            else{
                ans1=ans1+ans[i];
            }
        }
        return ans1;
    }
};