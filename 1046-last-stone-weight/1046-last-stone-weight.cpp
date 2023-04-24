class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1){
            return stones[0];
        }
        if(stones.size()==0){
            return 0;
        }
        sort(stones.begin(), stones.end());
        reverse(stones.begin(), stones.end());
        int temp=stones[0]-stones[1];
        stones.erase(stones.begin());
        stones.erase(stones.begin());
        if(temp>0){
            stones.push_back(temp);
        }
        return lastStoneWeight(stones);
    }
};