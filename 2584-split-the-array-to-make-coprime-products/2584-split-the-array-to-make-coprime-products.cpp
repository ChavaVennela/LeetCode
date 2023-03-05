class Solution {
public:
    void factorize(int a, unordered_map<int, int>& m){
        int i;
        for(i=2; a>1 && i*i<=a; i++){
            if(a%i==0){
                while(a%i==0){
                    m[i]++;
                    a=a/i;
                }
            }
        }
        if(a!=1){
            m[a]++;
        }
    }
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, int>m;
        int i;
        for(i=0; i<nums.size(); i++){
            factorize(nums[i], m);
        }
        unordered_map<int, int>a;
        for(i=0; i<nums.size(); i++){
            factorize(nums[i], a);
            int count=0;
            for(auto it=a.begin(); it!=a.end(); it++){
                if(it->second<m[it->first]){
                    count=1;
                    break;
                }
            }
            if(count==0 && i!=nums.size()-1){
                return i;
            }
        }
        return -1;
        return 0;
    }
};