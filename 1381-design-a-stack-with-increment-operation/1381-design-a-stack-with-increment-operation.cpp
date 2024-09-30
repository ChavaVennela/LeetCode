class CustomStack {
public:
    vector<int>a;
    int max_val;
    CustomStack(int maxSize) {
        max_val=maxSize;
    }
    
    void push(int x) {
        if(a.size()<max_val){
            a.push_back(x);
        }
    }
    
    int pop() {
        if(a.size()==0){
            return -1;
        }
        int temp=a[a.size()-1];
        a.erase(a.begin()+a.size()-1);
        return temp;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min((int)a.size(), k); i++){
            a[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */