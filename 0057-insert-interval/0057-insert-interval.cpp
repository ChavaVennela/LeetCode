class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> a;
        sort(intervals.begin(), intervals.end());
        int i, j, first, last;
        first = intervals[0][0];
        last = intervals[0][1];
        for(i=1; i<intervals.size(); i++){
            if(last >= intervals[i][0]){
                if(intervals[i][1] > last){
                    last =intervals[i][1];
                }
                if(intervals[i][0] < first){
                    first = intervals[i][0];
                }
            }
            else{
                vector<int>b;
                b.push_back(first);
                b.push_back(last);
                a.push_back(b);
                first = intervals[i][0];
                last = intervals[i][1];
            }
        }
        vector<int>b;
        b.push_back(first);
        b.push_back(last);
        a.push_back(b);
        return a;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};