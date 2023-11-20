class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        for(int i=0; i<garbage.size(); i++){
            ans+=garbage[i].size();
        }
        // cout<<ans<<endl;
        int m=0, p=0, g=0;
        for(int i=1; i<travel.size(); i++){
            travel[i]+=travel[i-1];
            // cout<<travel[i]<<" ";
        }
        // cout<<endl;
        int j=travel.size()-1;
        for(int i=garbage.size()-1; i>=0; i--){
            if(m==0 && garbage[i].find('M')<garbage[i].size()){
                ans+=travel[j];
                // cout<<ans<<" "<<garbage[i]<<endl;
                m=1;
            }
            if(g==0 && garbage[i].find('G')<garbage[i].size()){
                ans+=travel[j];
                // cout<<ans<<" "<<garbage[i]<<endl;
                g=1;
            }
            if(p==0 && garbage[i].find('P')<garbage[i].size()){
                ans+=travel[j];
                // cout<<ans<<" "<<garbage[i]<<endl;
                p=1;
            }
            j--;
            if(j<0){
                break;
            }
            if(m!=0 && g!=0 && p!=0){
                break;
            }
           
        }
        return ans;
    }
};