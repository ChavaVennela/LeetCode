class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxbit=0, ans=0;
        for(int i=0; i<nums.size(); i++){
            maxbit=maxbit | nums[i];
        }
        int size=pow(2, nums.size())-1;
        for(int i=1; i<=size; i++){
            string s=bitset<16>(i).to_string().substr(16-nums.size());;
            int temp=0;
            for(int j=0; j<s.size(); j++){
                if(s[j]=='1'){
                    temp=temp | nums[j];
                }
            }
            if(temp==maxbit){
                ans++;
            }
        }
        return ans;
    }
};