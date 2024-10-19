class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int>a;
        if(nums[0]==0){
            a.push_back(0);
        }
        else{
            a.push_back(1);
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==0){
                a.push_back(0);
            }
            else{
                if(nums[i-1]==1){
                    a[a.size()-1]++;
                }
                else{
                    a.push_back(1);
                }
            }
        }
        int count=0, temp=0;
        int i=0;
        for(int j=0; j<a.size(); j++){
            if(a[j]==0){
                temp+=1;
                k--;
            }
            else{
                temp+=a[j];
            }
            while(k<0 && i<a.size()){
                if(a[i]==0){
                    temp-=1;
                    k++;
                }
                else{
                    temp-=a[i];
                }
                i++;
            }
            count=max(count, temp);
        }
        return count;
    }
};