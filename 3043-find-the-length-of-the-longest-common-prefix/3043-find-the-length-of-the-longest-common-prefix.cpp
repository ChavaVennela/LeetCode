class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<int, int>a;
        int ans=0;
        for(int i=0; i<arr1.size(); i++){
            while(arr1[i]>0){
                a[arr1[i]]++;
                arr1[i]=arr1[i]/10;
            }
        }
        for(int i=0; i<arr2.size(); i++){
            while(arr2[i]>0){
                if(a.find(arr2[i])==a.end()){
                    arr2[i]=arr2[i]/10;
                }
                else{
                    string temp=to_string(arr2[i]);
                    ans=max(ans,(int)temp.size());
                    break;
                }
            }
        }
        return ans;
    }
};