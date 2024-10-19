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
        int count=1, lastfirst, lastlast;
        lastfirst=intervals[0][0];
        lastlast=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=lastfirst && intervals[i][1]<=lastlast){
                continue;
            }
            count++;
            lastfirst=intervals[i][0];
            lastlast=intervals[i][1];
        }
        return count;
    }
};