class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int, int>a;
        for(int i=0; i<hand.size(); i++){
            a[hand[i]]++;
        }
        while(!a.empty()){
            int curr=a.begin()->first;
            for(int i=0; i<groupSize; i++){
                if(a.find(curr+i)==a.end() || a[curr+i]==0){
                    return false;
                }
                a[curr+i]--;
                if(a[curr+i]<1){
                    a.erase(curr+i);
                }
            }
        }
        return true;
    }
};