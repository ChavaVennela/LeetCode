class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int>s;
        int i;
        for(i=0; i<nums.size(); i++){
            if(nums[i]%2!=0){
                nums[i]*=2;
            }
            s.insert(nums[i]);
        }
        auto bac=s.end();
        bac--;
        set<int>ans;
        ans.insert(*bac-*s.begin());
        while(*bac%2==0){
            int temp=*bac/2;
            s.erase(bac);
            s.insert(temp);
            bac=s.end();
            bac--;
            ans.insert(*bac-*s.begin());
        }
        return *ans.begin();
    }
};