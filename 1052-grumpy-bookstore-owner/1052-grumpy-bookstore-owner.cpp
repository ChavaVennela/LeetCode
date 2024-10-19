class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxunsatis=0, temp;
        for(int i=0; i<minutes; i++){
            maxunsatis+=(customers[i]*grumpy[i]);
        }
        temp=maxunsatis;
        for(int i=minutes; i<customers.size(); i++){
            temp+=(customers[i]*grumpy[i]);
            temp-=(customers[i-minutes]*grumpy[i-minutes]);
            maxunsatis=max(maxunsatis, temp);
        }
        for(int i=0; i<customers.size(); i++){
            maxunsatis+=(customers[i]*(1-grumpy[i]));
        }
        return maxunsatis;
    }
};