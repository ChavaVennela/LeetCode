class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>>a;
        for(int i=0; i<groupSizes.size(); i++){
            a[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto it=a.begin(); it!=a.end(); it++){
            vector<int>temp1=it->second;
            int j=0;
            for(int i=0; i<temp1.size()/it->first; i++){
                vector<int>temp(it->first, 0);
                for(int k=0; k<temp.size(); k++){
                    temp[k]=temp1[j];
                    j++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};