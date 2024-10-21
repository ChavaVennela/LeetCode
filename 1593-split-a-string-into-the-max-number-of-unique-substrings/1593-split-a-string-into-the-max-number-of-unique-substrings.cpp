class Solution {
public:
    int cal(string s, int start, unordered_set<string>&seen){
        if(start==s.size()){
            return 0;
        }
        int maxcount=0;
        for(int i=start+1; i<=s.size(); i++){
            string temp=s.substr(start, i-start);
            if(seen.find(temp)==seen.end()){
                seen.insert(temp);
                maxcount=max(maxcount, 1+cal(s, i, seen));
                seen.erase(temp);
            }
        }
        return maxcount;
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string>seen;
        return cal(s, 0, seen);
    }
};