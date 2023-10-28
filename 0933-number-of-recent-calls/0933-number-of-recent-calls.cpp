class RecentCounter {
public:
    int base=0;
    vector<int>a;
    RecentCounter() {
        base=0;
        a.clear();
    }
    
    int ping(int t) {
        a.push_back(t);
        if(a.size()==1){
            return 1;
        }
        else{
            if(t-a[base]<=3000){
                return a.size()-base;
            }
            else{
                for(int i=base+1; i<a.size(); i++){
                    if(t-a[i]<=3000){
                        base=i;
                        return a.size()-base;
                    }
                }
            }
        }
        return a.size()-base;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */