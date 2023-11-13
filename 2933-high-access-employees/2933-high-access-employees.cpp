class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(), access_times.end());
        int count=1, ini=0;
        map<string, int>a;
        vector<string>ans;
        for(int i=1; i<access_times.size(); i++){
            if(access_times[i][0]!=access_times[i-1][0]){
                if(a.find(access_times[i-1][0])==a.end()){
                    a[access_times[i-1][0]]=count;
                }
                else{
                    a[access_times[i-1][0]]=max(a[access_times[i-1][0]], count);
                }
                count=1;
                ini=i;
            }
            else{
                if(stoi(access_times[i][1])-stoi(access_times[ini][1]) <100){
                    count++;
                }
                else{
                    if(a.find(access_times[i][0])==a.end()){
                        a[access_times[i][0]]=count;
                    }
                    else{
                        a[access_times[i][0]]=max(a[access_times[i][0]], count);
                    }
                    for(int temp=ini+1; temp<=i; temp++){
                        if(stoi(access_times[i][1])-stoi(access_times[temp][1])<100){
                            ini=temp;
                            break;
                        }
                        count--;
                    }
                    if(count==0){
                        count=1;
                    }
                }
            }
            //cout<<access_times[i][0]<<" "<<count<<endl;
        }
        if(a.find(access_times[access_times.size()-1][0])==a.end()){
            a[access_times[access_times.size()-1][0]]=count;
        }
        else{
            a[access_times[access_times.size()-1][0]]=max(a[access_times[access_times.size()-1][0]], count);
        }
        for(auto it=a.begin(); it!=a.end(); it++){
            //cout<<it->first<<" "<<it->second<<endl;
            if(it->second>=3){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};