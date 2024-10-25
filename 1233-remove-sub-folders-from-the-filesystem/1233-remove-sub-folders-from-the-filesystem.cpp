class Solution {
public:
    static int count(string a){
        int ct=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]=='/'){
                ct++;
            }
        }
        return ct;
    }
    static bool cmp(string a, string b){
        if(count(a) != count(b)){
            return count(a)<count(b);
        }
        return a<b;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), cmp);
        unordered_map<string, int>a;
        a[folder[0]]++;
        for(int i=1; i<folder.size(); i++){
            if(count(folder[i])>1){
                string temp="/";
                int flag=0;
                for(int j=1; j<folder[i].size(); j++){
                    if(folder[i][j]!='/'){
                        temp+=folder[i][j];
                    }
                    else{
                        if(a.find(temp) != a.end()){
                            flag=1;
                            break;
                        }
                        temp+=folder[i][j];
                    }
                }
                if(flag==0){
                    a[temp]++;
                }
            }
            else{
                a[folder[i]]++;
            }
        }
        vector<string>ans;
        for(auto it=a.begin(); it!=a.end(); it++){
            ans.push_back(it->first);
        }
        return ans;
    }
};