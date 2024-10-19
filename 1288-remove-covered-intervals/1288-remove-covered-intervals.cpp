class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        return a[1]>b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>>temp;
        temp.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=temp[temp.size()-1][0] && intervals[i][1]<=temp[temp.size()-1][1]){
                continue;
            }
            temp.push_back(intervals[i]);
        }
        return temp.size();
    }
};