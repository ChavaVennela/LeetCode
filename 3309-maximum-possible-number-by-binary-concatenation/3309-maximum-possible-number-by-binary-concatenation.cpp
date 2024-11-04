class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        string s1=bitset<32>(nums[0]).to_string();
        string s2=bitset<32>(nums[1]).to_string();
        string s3=bitset<32>(nums[2]).to_string();
        while(s1[0]!='1'){
            s1.erase(0,1);
        }
        while(s2[0]!='1'){
            s2.erase(0,1);
        }
        while(s3[0]!='1'){
            s3.erase(0,1);
        }
        string ans=s1+s2+s3;
        if(s1+s3+s2>ans){
            ans=s1+s3+s2;
        }
        if(s2+s1+s3>ans){
            ans=s2+s1+s3;
        }
        if(s2+s3+s1>ans){
            ans=s2+s3+s1;
        }
        if(s3+s1+s2>ans){
            ans=s3+s1+s2;
        }
        if(s3+s2+s1>ans){
            ans=s3+s2+s1;
        }
        int res=stoi(ans, nullptr, 2);
        return res;
    }
};