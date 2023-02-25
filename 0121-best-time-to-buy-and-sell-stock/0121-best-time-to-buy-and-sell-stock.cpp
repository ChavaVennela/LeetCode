class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, j, profit, buy;
        profit=0;
        buy = prices[0];
        for(i=1; i<prices.size(); i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            if(prices[i]-buy > profit){
                profit = prices[i] -buy;
            }
        }
        return profit;
    }
};