class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        unordered_map<int, int>mymap;
        for(int i=0; i<nums.size(); i++){
            mymap[nums[i]]++;
        }
        int ans=0;
        for(auto it=mymap.begin(); it!=mymap.end(); it++){
            if(mymap.find(it->first-1)==mymap.end()){
                int count=1;
                int start=it->first;
                while(mymap.find(start+1)!=mymap.end()){
                    count++;
                    start++;
                }
                ans=max(ans, count);
            }
        }
        return ans;
    }
};