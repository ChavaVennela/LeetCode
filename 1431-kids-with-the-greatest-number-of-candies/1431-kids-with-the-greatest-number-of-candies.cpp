class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int i, max1=candies[0];
        for(i=1; i<candies.size(); i++){
            max1=max(max1, candies[i]);
        }
        for(i=0; i<candies.size(); i++){
            if(candies[i]+extraCandies>=max1){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};