class SeatManager {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int> > heap;
    SeatManager(int n) {
        for(int i=1; i<=n; i++){
            heap.push(i);
        }
    }
    
    int reserve() {
        int ans=heap.top();
        heap.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        heap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */