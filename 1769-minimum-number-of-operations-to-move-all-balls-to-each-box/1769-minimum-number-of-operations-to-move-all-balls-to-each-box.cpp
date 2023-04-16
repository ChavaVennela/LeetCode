class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>a;
        int i;
        vector<int>b;
        for(i=0; i<boxes.size(); i++){
            if(boxes[i]=='1'){
                b.push_back(i);
            }
        }
        for(i=0; i<boxes.size(); i++){
            int j, count=0;
            for(j=0; j<b.size(); j++){
                count+=abs(i-b[j]);
            }
            a.push_back(count);
        }
        return a;
    }
};