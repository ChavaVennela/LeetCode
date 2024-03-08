class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int>a;
        for(int i=0; i<nums.size(); i++){
            a[nums[i]]++;
        }
        int count=0, ans=0;
        for(auto it=a.begin(); it!=a.end(); it++){
            if(it->second>count){
                count=it->second;
                ans=it->second;
            }
            else if(it->second==count){
                ans+=it->second;
            }
        }
        return ans;
    }
};