class Solution {
public:
    int compress(vector<char>& chars) {
        int i, temp=1, j=0, len=chars.size();
        for(i=1; i<len; i++){
            if(chars[i]==chars[i-1]){
                temp++;
            }
            else{
                chars[j]=chars[i-1];
                j++;
                if(temp>1){
                    string temp1=to_string(temp);
                    for(int k=0; k<temp1.size(); k++){
                        chars[j]=temp1[k];
                        j++;
                    }
                }
                temp=1;
            }
        }
        chars[j]=chars[i-1];
        j++;
        if(temp>1){
            string temp1=to_string(temp);
            for(int k=0; k<temp1.size(); k++){
                chars[j]=temp1[k];
                j++;
            }
        }
        return j;
    }
};