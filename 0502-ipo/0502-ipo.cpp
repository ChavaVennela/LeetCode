class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>>a;
        int i, j=0;
        for(i=0; i<profits.size(); i++){
            a.push_back({capital[i], profits[i]});
        }
        sort(a.begin(), a.end());
        i=0;
        priority_queue<int>q;
        while(i<k){
            while(j<a.size() && a[j].first<=w){
                q.push(a[j].second);
                j++;
            }
            if(!q.empty()){
                w=w+q.top();
                q.pop();
                i++;
            }
            else{
                break;
            }
        }
        return w;
    }
};