class Solution {
public:
    vector<int> cal(int a, int sizeval){
        vector<int>ans;
        while(a>0){
            ans.push_back(a%2);
            a=a/2;
        }
        reverse(ans.begin(), ans.end());
        while(ans.size()<sizeval){
            ans.insert(ans.begin(), 0);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int maxval=*max_element(nums.begin(), nums.end());
        if(maxval==0){
            if(k==0){
                return 1;
            }
            return -1;
        }
        vector<int>a((int)log2(maxval)+1, 0);
        int start=0, currbitwise=0, count=INT_MAX;
        unordered_map<int, vector<int>>mymap;
        for(int i=0; i<nums.size(); i++){
            if(mymap.find(nums[i])==mymap.end()){
                mymap[nums[i]]=cal(nums[i], a.size());
            }
        }
        vector<int>currones(a.size(), 0);
        for(int j=0; j<nums.size(); j++){
            for(int i=0; i<a.size(); i++){
                currones[i]+=mymap[nums[j]][i];
            }
            currbitwise= currbitwise | nums[j];
            while(currbitwise>=k && start<=j){
                for(int i=0; i<a.size(); i++){
                    currones[i]-=mymap[nums[start]][i];
                }
                int val=0;
                for(int i=0; i<a.size(); i++){
                    if(currones[i]!=0){
                        val+=pow(2, a.size()-i-1);
                    }
                }
                currbitwise=val;
                count=min(count, j-start+1);
                start++;
            }    
        }
        if(count==INT_MAX){
            return -1;
        }
        return count;
    }
};