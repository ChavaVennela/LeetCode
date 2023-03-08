class Solution {
public:
    long long check(vector<int>piles, int k){
        long long count=0, i=0;
        for(i=0; i<piles.size(); i++){
            count+=ceil((double)piles[i]/k);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int r=piles[piles.size()-1], l=1, mid;
        vector<int>ans;
        while(l<=r){
            mid=l+(r-l)/2;
            if(check(piles, mid)>h){
                l=mid+1;
            }
            else{
                ans.push_back(mid);
                r=mid-1;
            }
        }
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};