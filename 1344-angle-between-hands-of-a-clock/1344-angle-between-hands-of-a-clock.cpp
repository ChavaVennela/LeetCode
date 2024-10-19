class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans=0;
        double minpla= ((double)minutes*6);
        if(minpla==360){
            minpla=0;
        }
        double hours;
        if(hour==12){
            hours=0;
        }
        else{
            hours=hour*30;
        }
        hours+=(double)minutes/2;
        return min(360-(abs(hours-minpla)), abs(hours-minpla));
    }
};