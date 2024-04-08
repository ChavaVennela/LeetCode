class Solution {
public:
    map<pair<int, int>, bool>a;
    bool valid(string s, int idx, int count){
        if(a.find({idx, count})!=a.end()){
            return a[{idx, count}];
        }
        if(idx==s.size()){
            if(count!=0){
                return false;
            }
            return true;
        }
        if(s[idx]=='('){
            a[{idx, count}]=valid(s, idx+1, count+1);
            count++;
            return a[{idx, count-1}];
        }
        else if(s[idx]==')'){
            if(count>0){
                a[{idx, count}]=valid(s, idx+1, count-1);
                count--;
                return a[{idx, count+1}];
            }
            else{
                a[{idx, count}]=false;
                return false;
            }
        }
        else{
            if(count==0){
                a[{idx, count}]=valid(s, idx+1, count) | valid(s, idx+1, count+1);
            }
            else{
                a[{idx, count}]=valid(s, idx+1, count) | valid(s, idx+1, count+1) | valid(s, idx+1, count-1);
            }
            return a[{idx, count}];
        }
    }
    bool checkValidString(string s) {
        return valid(s, 0, 0);
    }
};