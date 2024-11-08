class Solution {
public:
    int check(string a){
        int ans=0;
        for(int i=a.size()-1; i>=0; i--){
            ans+=(a[i]-'0')*(pow(2, a.size()-i-1));
        }
        return ans;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<string>a;
        for(int i=0; i<nums.size(); i++){
            string temp=bitset<32>(nums[i]).to_string();
            temp=temp.substr(temp.length()-maximumBit);
            if(a.size()==0){
                a.push_back(temp);
            }
            else{
                string temp1="";
                for(int j=0; j<temp.size(); j++){
                    if(temp[j]==a[a.size()-1][j]){
                        temp1+='0';
                    }
                    else{
                        temp1+='1';
                    }
                }
                a.push_back(temp1);
            }
        }
        vector<int>ans;
        for(int i=a.size()-1; i>=0; i--){
            string temp="";
            for(int j=0; j<a[i].size(); j++){
                if(a[i][j]=='1'){
                    temp+='0';
                }
                else{
                    temp+='1';
                }
            }
            int temp1=check(temp);
            ans.push_back(temp1);
        }
        return ans;
    }
};