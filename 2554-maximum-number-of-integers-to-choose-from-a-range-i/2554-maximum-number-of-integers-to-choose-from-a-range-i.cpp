class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        map<int, int>a;
        for(int i=0; i<banned.size(); i++){
            a[banned[i]]++;
        }
        int curr=0, count=0;
        for(int i=1; i<=n; i++){
            if(a.find(i)==a.end()){
                if(i+curr<=maxSum){
                    count++;
                    curr+=i;
                }
                else{
                    break;
                }
            }
            if(curr==maxSum){
                return count;
            }
        }
        return count;
    }
};