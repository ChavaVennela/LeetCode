class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int front=0, last=tokens.size()-1, score=0;
        while(front<=last){
            if(tokens[front]<=power){
                power-=tokens[front];
                score++;
                front++;
            }
            else if(power<tokens[front] && front != last && score>0){
                power+=tokens[last];
                last--;
                score--;
            }
            else{
                break;
            }
        }
        return score;
    }
};