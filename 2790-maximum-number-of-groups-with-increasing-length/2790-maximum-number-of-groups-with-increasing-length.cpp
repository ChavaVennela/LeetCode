class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        int i;
        long long total=0, count=0;
        for(i=0; i<usageLimits.size(); i++){
            total+=usageLimits[i];
            if(total>=(count+1)*(count+2)/2){
                count++;
            }
        }
        return count;
    }
};