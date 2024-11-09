class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        map<int, int>mymap;
        int prev=nums[0];
        for(int i=0; i<nums.size(); i++){
            mymap[nums[i]]++;
            prev=min(nums[i], prev);
        }
        int count=1, ans=1;
        for(auto it=mymap.begin(); it!=mymap.end(); it++){
            if(it->first==prev){
                continue;
            }
            if(it->first==prev+1){
                count++;
            }
            else{
                ans=max(count, ans);
                count=1;
            }
            prev=it->first;
        }
        ans=max(count, ans);
        return ans;
    }
};