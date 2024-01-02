class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        int count=1;
        while(count==1){
            unordered_set<int>a;
            vector<int>temp;
            count=0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]!=0 && a.find(nums[i])==a.end()){
                    a.insert(nums[i]);
                    temp.push_back(nums[i]);
                    nums[i]=0;
                    count=1;
                }
            }
            if(temp.size()>0){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};