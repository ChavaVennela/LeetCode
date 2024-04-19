class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            string temp=to_string(nums[i]);
            if(temp.size()>1){
                sort(temp.begin(), temp.end());
                for(int j=temp.size()-2; j>=0; j--){
                    temp[j]=temp[j+1];
                }
            }
            ans+=stoi(temp);
        }
        return ans;
    }
};