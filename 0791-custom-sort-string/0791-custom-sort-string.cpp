class Solution {
public:
    struct cmp{
        string order;
        cmp(const string& order) : order(order) {}
        bool operator() (char a, char b) const {
            auto posA = order.find(a);
            auto posB = order.find(b);
            if(posA == string::npos && posB == string::npos){
                return a < b;
            } 
            if(posA == string::npos){
                return false;
            }
            if(posB == string::npos){
                return true;
            }
            return posA < posB;
        }
    };
    string customSortString(string order, string s) {
        cmp comp(order);
        sort(s.begin(), s.end(), comp);
        return s;
    }
};