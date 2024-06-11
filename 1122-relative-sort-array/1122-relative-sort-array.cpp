class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int>a;
        for(int i=0; i<arr1.size(); i++){
            a[arr1[i]]++;
        }
        vector<int>ans;
        for(int i=0; i<arr2.size(); i++){
            for(int j=0; j<a[arr2[i]]; j++){
                ans.push_back(arr2[i]);
            }
            a[arr2[i]]=0;
        }
        for(auto it=a.begin(); it!=a.end(); it++){
            if(it->second>0){
                for(int i=0; i<it->second; i++){
                    ans.push_back(it->first);
                }
            }
        }
        return ans;
    }
};