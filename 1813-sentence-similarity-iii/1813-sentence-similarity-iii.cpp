class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string>a1;
        deque<string>b1;
        string temp="";
        for(int i=0; i<sentence1.size(); i++){
            if(sentence1[i]==' ' && temp!=""){
                a1.push_back(temp);
                temp="";
            }
            else{
                temp+=sentence1[i];
            }
        }
        if(temp!=""){
            a1.push_back(temp);
            temp="";
        }
        for(int i=0; i<sentence2.size(); i++){
            if(sentence2[i]==' ' && temp!=""){
                b1.push_back(temp);
                temp="";
            }
            else{
                temp+=sentence2[i];
            }
        }
        if(temp!=""){
            b1.push_back(temp);
        }
        while(!a1.empty() && !b1.empty() && a1.front()==b1.front()){
            a1.pop_front();
            b1.pop_front();
        }
        while(!a1.empty() && !b1.empty() && a1.back()==b1.back()){
            a1.pop_back();
            b1.pop_back();
        }
        return a1.empty() || b1.empty();
    }
};