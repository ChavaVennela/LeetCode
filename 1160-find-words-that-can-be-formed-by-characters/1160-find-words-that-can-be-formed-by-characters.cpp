class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int>a;
        int i, j, count=0;
        for(i=0; i<chars.size(); i++){
            a[chars[i]]++;
        }
        for(i=0; i<words.size(); i++){
            unordered_map<char, int>temp(a);
            if(words[i].size()<=chars.size()){
                int flag=0;
                for(j=0; j<words[i].size(); j++){
                    if(temp.find(words[i][j]) != temp.end() && temp[words[i][j]]>0){
                        temp[words[i][j]]--;
                    }
                    else{
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    count=count+words[i].size();
                }
            }
        }
        return count;
    }
};