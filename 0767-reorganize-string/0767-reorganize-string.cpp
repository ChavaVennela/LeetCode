class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>>a;
        vector<int>freq(26, 0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        for(int i=0; i<freq.size(); i++){
            if(freq[i]!=0){
                a.push({freq[i], i+'a'});
            }
        }
        string ans="";
        while(!a.empty()){
            pair<int, char>temp=a.top();
            a.pop();
            ans+=temp.second;
            if(temp.first>1){
                if(a.empty()){
                    return "";
                }
                pair<int, char>temp1=a.top();
                a.pop();
                ans+=temp1.second;
                if(temp1.first-1>0){
                    a.push({temp1.first-1, temp1.second});
                }
            }
            if(temp.first-1>0){
                a.push({temp.first-1, temp.second});
            }
        }
        return ans;
    }
};