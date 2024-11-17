class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int>zeropos;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                zeropos.push_back(i);
            }
        }
        if(zeropos.size()==nums.size()){
            return nums.size()*2;
        }
        int count=0;
        for(int i=0; i<zeropos.size(); i++){
            for(int k=0; k<2; k++){
                int dir=k, j=zeropos[i];
                if(dir==0){
                    j--;
                }
                else{
                    j++;
                }
                vector<int>temp=nums;
                while(j>=0 && j<temp.size()){
                    if(temp[j]!=0){
                        temp[j]--;
                        if(dir==0){
                            dir=1;
                        }
                        else{
                            dir=0;
                        }
                    }
                    if(dir==0){
                        j--;
                    }
                    else{
                        j++;
                    }
                }
                int flag=0;
                for(int j=0; j<temp.size(); j++){
                    if(temp[j]!=0){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    count++;
                }
            } 
        }
        return count;
    }
};