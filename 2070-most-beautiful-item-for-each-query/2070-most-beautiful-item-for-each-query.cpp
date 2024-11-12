class Solution {
public:
    int check(vector<vector<int>>&items, int target){
        int start=0, end=items.size()-1;
        int maxbeauty=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(items[mid][0]>target){
                end=mid-1;
            }
            else{
                maxbeauty=max(maxbeauty, items[mid][1]);
                start=mid+1;
            }
        }
        return maxbeauty;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        int maxbeauty=items[0][1];
        for(int i=0; i<items.size(); i++){
            maxbeauty=max(maxbeauty, items[i][1]);
            items[i][1]=maxbeauty;
        }
        vector<int>ans(queries.size(), 0);
        for(int i=0; i<queries.size(); i++){
            ans[i]=check(items, queries[i]);
        }
        return ans;
    }
};