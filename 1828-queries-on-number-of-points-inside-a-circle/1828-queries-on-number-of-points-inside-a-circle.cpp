class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        map<pair<int, int>, int>mymap;
        int i, j;
        vector<int>ans;
        for(i=0; i<points.size(); i++){
            mymap[{points[i][0], points[i][1]}]++;
        }
        for(i=0; i<queries.size(); i++){
            int count=0;
            for(auto it=mymap.begin(); it!=mymap.end(); it++){
                double dis=sqrt(pow(it->first.first-queries[i][0], 2)+pow(it->first.second-queries[i][1], 2));
                if(dis<=(double)queries[i][2]){
                    count+=it->second;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};