class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        auto it=m.begin();
        for(int i=0; i<nums.size(); i++){
            if(it->second>0){
                nums[i]=it->first;
                it->second--;
            }
            else{
                it++;
                nums[i]=it->first;
                it->second--;
            }
        }
        return nums;
    }
};