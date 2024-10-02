class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int>a;
        int count=0;
        for(int i=0; i<arr.size(); i++){
            a[arr[i]]=1;
        }
        for(auto it=a.begin(); it!=a.end(); it++){
            it->second+=count;
            count++;
        }
        for(int i=0; i<arr.size(); i++){
            arr[i]=a[arr[i]];
        }
        return arr;
    }
};