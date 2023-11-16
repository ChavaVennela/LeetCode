class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int>a;
        for(int i=0; i<nums.size(); i++){
            a.insert(stoi(nums[i], nullptr, 2));
        }
        for(int i=0; i<nums.size()+1; i++){
            if(a.find(i)==a.end()){
                string ans=bitset<64> (i).to_string();
                return ans.substr(ans.size()-nums.size());
            }
        }
        string ans=bitset<64> (nums.size()+1).to_string();
        return ans.substr(ans.size()-nums.size());
    }
};