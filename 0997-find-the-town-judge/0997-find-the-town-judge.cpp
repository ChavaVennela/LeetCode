class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int i;
        vector<int>a(n+1);
        for(i=0; i<trust.size(); i++){
            a[trust[i][0]]++;
        }
        int ju=0, count=0;
        for(i=1; i<a.size(); i++){
            if(a[i]==0){
                ju=i;
                count++;
            }
        }
        vector<int>b(n+1, 0);
        if(count!=1){
            return -1;
        }
        for(i=0; i<trust.size(); i++){
            if(trust[i][1]==ju){
                b[trust[i][0]]++;
            }
        }
        count=0;
        for(i=1; i<b.size(); i++){
            if(b[i]==0 && i!=ju){
                return -1;
            }
            if(i!=ju){
                count++;
            }
        }
        if(count!=n-1){
            return -1;
        }
        return ju;
    }
};