class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        string s1 = bitset<32>(left).to_string();
        string s2 = bitset<32>(right).to_string();
        string s3="";
        int count=0;
        for(int i=0; i<s1.size(); i++){
            if(count==1){
                s3+="0";
            }
            else if(count==0 && s1[i]==s2[i]){
                s3+=s1[i];
            }
            else{
                count=1;
                s3+="0";
            }
        }
        return stoi(s3, 0, 2);
    }
};