class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0, count=0;
        unordered_map<int, int>a;
        for(i=0; i<arr.size(); i++){
            a[arr[i]]++;
        }
        i=1;
        while(count!=k){
            if(a.find(i)==a.end()){
                count++;
            }
            i++;
        }
        return i-1;
    }
};