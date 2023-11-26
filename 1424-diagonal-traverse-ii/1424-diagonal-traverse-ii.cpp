class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>>a;
        vector<int>ans;
        int count=0;
        for(int i=nums.size()-1; i>=0; i--){
            for(int j=0; j<nums[i].size(); j++){
                a[i+j].push_back(nums[i][j]);
            }
        }
        while(a.find(count)!=a.end()){
            for(int i=0; i<a[count].size(); i++){
                ans.push_back(a[count][i]);
            }
            count++;
        }
        return ans;
    }
};