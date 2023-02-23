class Solution {
public:
    bool isHappy(int n) {
        set<int>a;
        int i, j, p;
        bool ans=false;
        while(a.find(n) == a.end()){
            if(n==1){
                ans=true;
                break;
            }
            a.insert(n);
            string s=to_string(n);
            p=0;
            for(i=0; i<s.size(); i++){
               p = p+ pow((s[i]-'0'), 2); 
            }
            n=p;
        }
        return ans;
    }
};