class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky=false, heavy=false;
        if(mass>=100){
            heavy=true;
        }
        if(max(length, max(width, height))>=10000){
            bulky=true;
        }
        else{
            long long int vol;
            vol=(long long int)length*(long long int)width*(long long int)height;
            if(vol>=1000000000){
                bulky=true;
            }
        }
        if(heavy && bulky){
            return "Both";
        }
        if(!(heavy || bulky)){
            return "Neither";
        }
        if(heavy){
            return "Heavy";
        }
        return "Bulky";
    }
};