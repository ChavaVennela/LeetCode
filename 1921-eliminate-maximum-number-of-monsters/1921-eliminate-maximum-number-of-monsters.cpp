class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>time;
        for(int i=0; i<dist.size(); i++){
            time.push_back(float(dist[i])/float(speed[i]));
        }
        sort(time.begin(), time.end());
        int count=0;
        for(int i=0; i<time.size(); i++){
            if(i>=time[i]){
                break;
            }
            count++;
        }
        return count;
    }
};