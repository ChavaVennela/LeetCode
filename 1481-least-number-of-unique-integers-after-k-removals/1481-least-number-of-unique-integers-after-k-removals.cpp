class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int>a;
        for(int i=0; i<arr.size(); i++){
            a[arr[i]]++;
        }
        vector<int>count;
        for(auto it=a.begin(); it!=a.end(); it++){
            count.push_back(it->second);
        }
        sort(count.begin(), count.end());
        int count1=0;
        for(int i=0; i<count.size(); i++){
            count1+=count[i];
            if(count1>k){
                return count.size()-i;
            }
        }
        return 0;
    }
};