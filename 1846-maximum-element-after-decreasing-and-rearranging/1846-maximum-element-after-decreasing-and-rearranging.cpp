class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if(arr.size()==1){
            return 1;
        }
        sort(arr.begin(), arr.end());
        for(int i=1; i<arr.size(); i++){
            arr[i]=min(arr[i], min(i+1, arr[i-1]+1));
        }
        return arr[arr.size()-1];
    }
};