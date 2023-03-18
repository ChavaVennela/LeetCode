class BrowserHistory {
public:
    int pos=-1;
    vector<string>a;
    BrowserHistory(string homepage) {
        a.push_back(homepage);
    }
    
    void visit(string url) {
        if(pos==-1 || pos==a.size()-1){
            pos=-1;
            a.push_back(url);
        }
        else{
            a.erase(a.begin()+pos+1, a.end());
            pos=-1;
            a.push_back(url);
        }
    }
    
    string back(int steps) {
        if(pos==-1){
            pos=a.size()-1;
        }
        if(pos-steps<0){
            pos=0;
            return a[pos];
        }
        pos=pos-steps;
        return a[pos];
    }
    
    string forward(int steps) {
        if(pos==-1){
            pos=a.size()-1;
        }
        if(pos+steps>=a.size()){
            pos=a.size()-1;
            return a[pos];
        }
        pos=pos+steps;
        return a[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */