class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>>mymap;
        int i;
        for(i=0; i<paths.size(); i++){
            string s=paths[i];
            string s1="", s2="", val="";
            int count=0;
            for(int j=0; j<s.size(); j++){
                if(count==0 && s[j]==' '){
                    count=1;
                    s2=s2+'/';
                    s1=s2;
                }
                else if(count==0){
                    s2=s2+s[j];
                }
                else if(count==1){
                    if(s[j]==' '){
                        s2=s1;
                    }
                    else if(s[j]=='('){
                        count=2;
                    }
                    else{
                        s2=s2+s[j];
                    }
                }
                else if(count==2){
                    if(s[j]==')'){
                        count=1;
                        mymap[val].push_back(s2);
                        val="";
                    }
                    else{
                        val=val+s[j];
                    }
                }
            }
        }
        vector<vector<string>>ans;
        for(auto it=mymap.begin(); it!=mymap.end(); it++){
            if(it->second.size()>1){
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};