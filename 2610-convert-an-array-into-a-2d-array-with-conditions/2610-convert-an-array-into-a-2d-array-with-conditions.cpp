class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int>mymap;
        int i, j, count=0;
        for(i=0; i<nums.size(); i++){
            mymap[nums[i]]++;
            count=max(count, mymap[nums[i]]);
        }
        vector<vector<int>>ans(count);
        for(auto it=mymap.begin(); it!=mymap.end(); it++){
            for(i=0; i<it->second; i++){
                ans[i].push_back(it->first);
            }
        }
        return ans;
    }
};