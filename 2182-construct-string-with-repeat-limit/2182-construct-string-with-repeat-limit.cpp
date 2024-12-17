class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int>a;
        for(int i=0; i<s.size(); i++){
            a[s[i]]++;
        }
        priority_queue<pair<char, int>>pq;
        for(auto it=a.begin(); it!=a.end(); it++){
            pq.push({it->first, it->second});
        }
        string ans="";
        while(!pq.empty()){
            pair<char, int>temp=pq.top();
            pq.pop();
            if(temp.second<=repeatLimit){
                for(int i=0; i<temp.second; i++){
                    ans+=temp.first;
                }
                temp.second=0;
            }
            else if(temp.second>repeatLimit){
                for(int i=0; i<repeatLimit; i++){
                    ans+=temp.first;
                }
                temp.second=temp.second-repeatLimit;
                if(!pq.empty()){
                    pair<char, int>temp1=pq.top();
                    pq.pop();
                    ans+=temp1.first;
                    if(temp1.second-1>0){
                        pq.push({temp1.first, temp1.second-1});
                    }
                    pq.push({temp.first, temp.second});
                }
            }
        }
        return ans;
    }
};