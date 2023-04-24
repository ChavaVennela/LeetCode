class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0, i, can=capacity;
        for(i=0; i<plants.size(); i++){
            if(can>=plants[i]){
                ans++;
                can-=plants[i];
            }
            else{
                ans+=(2*i)+1;
                can=capacity-plants[i];
            }
        }
        return ans;
    }
};