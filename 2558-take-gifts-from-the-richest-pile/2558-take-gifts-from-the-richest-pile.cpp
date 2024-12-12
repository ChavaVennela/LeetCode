class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>q;
        for(int i=0; i<gifts.size(); i++){
            q.push(gifts[i]);
        }
        for(int i=0; i<k; i++){
            int top=q.top();
            q.pop();
            q.push(sqrt(top));
        }
        long long ans=0;
        while(!q.empty()){
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};