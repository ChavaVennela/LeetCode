class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        string ans="";
        a>0 ? pq.push({a, 'a'}) : void();
        b>0 ? pq.push({b, 'b'}) : void();
        c>0 ? pq.push({c, 'c'}) : void();
        while(!pq.empty()){
            pair<int, char>temp=pq.top();
            pq.pop();
            if(ans.length()>=2 && ans[ans.size()-1]==temp.second && ans[ans.size()-2]==temp.second){
                if(pq.empty()){
                    break;
                }
                pair<int, char>temp1=pq.top();
                pq.pop();
                ans+=temp1.second;
                temp1.first-1 > 0 ? pq.push({temp1.first-1, temp1.second}) : void();
            }
            ans+=temp.second;
            temp.first-1>0 ? pq.push({temp.first-1, temp.second}) : void();
        }
        return ans;
    }
};