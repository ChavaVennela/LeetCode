class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>track(seq.size(), 0);
        stack<char>a;
        int maxlen=0;
        for(int i=0; i<seq.size(); i++){
            if(seq[i]=='('){
                a.push(seq[i]);
                track[i]=a.size();
                maxlen=max(maxlen, (int)a.size());
            }
            else{
                track[i]=a.size();
                a.pop();
            }
        }
        for(int i=0; i<track.size(); i++){
            if(track[i]>maxlen/2){
                track[i]=1;
            }
            else{
                track[i]=0;
            }
        }
        return track;
    }
};