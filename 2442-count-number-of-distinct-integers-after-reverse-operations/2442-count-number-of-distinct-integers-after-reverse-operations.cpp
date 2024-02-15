class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int>a;
        for(int i=0; i<nums.size(); i++){
            string b=to_string(nums[i]);
            reverse(b.begin(), b.end());
            int b1=stoi(b);
            a.insert(nums[i]);
            a.insert(b1);
        }
        return a.size();
    }
};