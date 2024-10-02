class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int>a;
        for(int i=0; i<arr.size(); i++){
            arr[i]=((arr[i]%k)+k)%k;
            a[arr[i]]++;
        }
        for(auto it=a.begin(); it!=a.end(); it++){
            if(it->second>0){
                if(it->first == 0 || k-it->first ==it->first){
                    if(it->second%2!=0){
                        return false;
                    }
                }
                else if(a[k-it->first]==it->second){
                    a[it->first]=0;
                    a[k-it->first]=0;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};