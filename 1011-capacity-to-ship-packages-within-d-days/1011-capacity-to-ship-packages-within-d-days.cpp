class Solution {
public:
    int check(vector<int>weights, int cap, int days){
        int i, count=0, d=0, max1=0;
        for(i=0; i<weights.size(); i++){
            if(count+weights[i]<=cap){
                count+=weights[i];
            }
            else{
                d++;
                max1=max(max1, count);
                count=weights[i];
            }
        }
        d++;
        if(d==days){
            return cap;
        }
        else if(d<days){
            return -2;
        }
        else{
            return -1;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int i, low, high=0, max1=weights[0];
        for(i=0; i<weights.size(); i++){
            high+=weights[i];
            if(weights[i]>max1){
                max1=weights[i];
            }
        }
        if(days==1){
            return high;
        }
        low=max1;
        while(low<high){
            int mid=low+(high-low)/2;
            int temp=check(weights, mid, days);
            if(temp>0){
                high=temp;
            }
            else if(temp==-1){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};