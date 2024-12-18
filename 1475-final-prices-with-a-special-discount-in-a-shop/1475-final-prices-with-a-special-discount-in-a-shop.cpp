class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>>a;
        for(int i=0; i<prices.size(); i++){
            if(a.empty()){
                a.push({prices[i], i});
            }
            else{
                while(!a.empty() && a.top().first>=prices[i]){
                    prices[a.top().second]-=prices[i];
                    a.pop();
                }
                a.push({prices[i], i});
            }
        }
        return prices;
    }
};