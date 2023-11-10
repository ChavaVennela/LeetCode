class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int>ans;
        map<int, vector<int>>b;
        set<int>c;
        for(int i=0; i<adjacentPairs.size(); i++){
            b[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            b[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        stack<int>a;
        for(auto it=b.begin(); it!=b.end(); it++){
            if(it->second.size()==1){
                a.push(it->first);
                break;
            }
        }
        while(!a.empty()){
            int temp=a.top();
            a.pop();
            if(c.find(temp)==c.end()){
                c.insert(temp);
                ans.push_back(temp);
            }
            else{
                continue;
            }
            vector<int>temp1=b[temp];
            for(int i=0; i<temp1.size(); i++){
                if(c.find(temp1[i])==c.end()){
                    a.push(temp1[i]);
                } 
            }
        }
        return ans;
    }
};