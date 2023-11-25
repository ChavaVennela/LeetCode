class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>ans;
        vector<int>forward;
        vector<int>back;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                forward.push_back(nums[i]);
                back.push_back(nums[nums.size()-1]);
            }
            else{
                forward.push_back(forward[i-1]+nums[i]);
                back.push_back(back[i-1]+nums[nums.size()-1-i]);
            }
        }
        reverse(back.begin(), back.end());
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                ans.push_back(back[i]-(nums.size()*nums[i]));
            }
            else if(i==nums.size()-1){
                ans.push_back((nums[i]*nums.size())-forward[i]);
            }
            else{
                int temp=(nums[i]*(i+1))-forward[i];
                int temp1=back[i]-(nums[i]*(nums.size()-i));
                ans.push_back(temp+temp1);
            }
        }
        return ans;
    }
};