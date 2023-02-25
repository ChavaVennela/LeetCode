class Solution {
public:
    int gcd(int a, int b){
        if(a==0){
            return b;
        }
        return gcd(b%a, a);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1){
            return "";
        }
        int a=str1.size(), b=str2.size(), i;
        int c=gcd(a, b);
        return str1.substr(0,c);
    }
};