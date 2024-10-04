class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long count=0, sum;
        sort(skill.begin(), skill.end());
        sum=skill[0]+skill[skill.size()-1];
        for(int i=0; i<skill.size()/2; i++){
            if(skill[i]+skill[skill.size()-1-i]==sum){
                count+=skill[i]*skill[skill.size()-1-i];
            }
            else{
                return -1;
            }
        }
        return count;
    }
};