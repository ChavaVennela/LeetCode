class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        map<long long, vector<int>>freqtonum;
        map<int, long long>numtofreq;
        vector<long long>ans(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(numtofreq.find(nums[i])!=numtofreq.end()){
                auto it = std::find(freqtonum[numtofreq[nums[i]]].begin(), freqtonum[numtofreq[nums[i]]].end(),nums[i]); 
                if (it != freqtonum[numtofreq[nums[i]]].end()) { 
                    freqtonum[numtofreq[nums[i]]].erase(it); 
                }
                if(freqtonum[numtofreq[nums[i]]].size()==0){
                    freqtonum.erase(numtofreq[nums[i]]);
                }
            }
            numtofreq[nums[i]]+=freq[i];
            freqtonum[numtofreq[nums[i]]].push_back(nums[i]);
            auto it=prev(freqtonum.end());
            ans[i]=it->first;
        }
        return ans;
    }
};