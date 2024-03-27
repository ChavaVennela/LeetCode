class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>a;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                a.insert(nums[i]);
            }
        }
        int temp=1;
        for(auto it=a.begin(); it!=a.end(); it++){
            if(temp!=*it){
                return temp;
            }
            temp++;
        }
        return temp;
    }
};