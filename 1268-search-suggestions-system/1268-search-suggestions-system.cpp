class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string temp="";
        vector<vector<string>>ans;
        for(int i=0; i<searchWord.size(); i++){
            temp+=searchWord[i];
            int pos=products.size();
            vector<string>search;
            for(int j=0; j<products.size(); j++){
                if(products[j].substr(0, temp.size())==temp){
                    pos=j;
                    break;
                }
            }
            int count=0;
            for(int j=pos; j<products.size(); j++){
                if(count==3 || products[j].substr(0, temp.size())!=temp){
                    break;
                }
                else{
                    search.push_back(products[j]);
                    count++;
                }
            }
            ans.push_back(search);
        }
        return ans;
    }
};