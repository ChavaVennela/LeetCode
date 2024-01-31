class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>s;
        int i;
        vector<int>ans;
        s.push({temperatures[temperatures.size()-1], 0});
        ans.push_back(0);
        for(i=temperatures.size()-2; i>=0; i--){
            if(temperatures[i] < s.top().first){
                s.push({temperatures[i], 1});
                ans.push_back(1);
            }
            else{
                int count=0, flag=0;
                while(!s.empty()){
                    if(s.top().first <= temperatures[i]){
                        count=count+s.top().second;
                        s.pop();
                    }
                    else{
                        flag=1;
                        count++;
                        break;
                    }
                }
                if(flag==1){
                    s.push({temperatures[i], count});
                    ans.push_back(count);
                }
                else{
                    s.push({temperatures[i], 0});
                    ans.push_back(0);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};