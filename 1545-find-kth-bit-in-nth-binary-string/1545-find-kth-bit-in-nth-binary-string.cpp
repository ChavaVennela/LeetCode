class Solution {
public:
    char findKthBit(int n, int k) {
        string ini="0";
        for(int i=1; i<n; i++){
            string temp=ini;
            for(int j=0; j<temp.size(); j++){
                if(temp[j]=='0'){
                    temp[j]='1';
                }
                else{
                    temp[j]='0';
                }
            }
            reverse(temp.begin(), temp.end());
            ini+="1";
            ini+=temp;
            if(ini.size()>=k){
                break;
            }
        }
        return ini[k-1];
    }
};