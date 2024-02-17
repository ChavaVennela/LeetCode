class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, std::vector<int>, greater<int> >q;
        for(int i=1; i<heights.size(); i++){
            int diff=heights[i]-heights[i-1];
            if(diff>0){
                if(q.size()<ladders){
                    q.push(diff);
                }
                else{
                    if(q.empty() || q.top()>=diff){
                        bricks-=diff;
                    }
                    else{
                        int currmin=q.top();
                        q.pop();
                        q.push(diff);
                        bricks-=currmin;
                    }
                }
            }
            if(bricks<0){
                return i-1;
            }
        }
        return heights.size()-1;
    }
};