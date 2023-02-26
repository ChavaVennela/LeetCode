class Solution {
public:
    vector<vector<int>>a;
    int check(int indx1, int indx2, string word1, string word2){
        if(indx1==0){
            return indx2;
        }
        if(indx2==0){
            return indx1;
        }
        if(a[indx1][indx2]!=-1){
            return a[indx1][indx2];
        }
        int temp1=0;
        if(word1[indx1-1]==word2[indx2-1]){
            temp1=check(indx1-1, indx2-1, word1, word2);
        }
        else{
            temp1=min(check(indx1-1, indx2-1, word1, word2), min(check(indx1-1, indx2, word1, word2), check(indx1, indx2-1, word1, word2)))+1;
        }
        a[indx1][indx2]=temp1;
        return temp1;
    }
    int minDistance(string word1, string word2) {
        a.resize(word1.size()+1, vector<int>(word2.size()+1, -1));
        return check(word1.size(), word2.size(), word1, word2);
    }
};