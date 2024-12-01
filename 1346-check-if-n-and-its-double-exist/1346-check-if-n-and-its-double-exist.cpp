class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int>a;
        for(int i=0; i<arr.size(); i++){
            a[arr[i]]++;
        }
        for(int i=0; i<arr.size(); i++){
            if(a.find(arr[i]*2)!=a.end()){
                if(arr[i]==0 && a[arr[i]]>1){
                    return true;
                }
                else if(arr[i]!=0){
                    return true;
                }
            }
        }
        return false;
    }
};