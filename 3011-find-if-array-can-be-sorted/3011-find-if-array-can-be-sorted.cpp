class Solution {
public:
    int check(int a){
        string temp=bitset<32>(a).to_string();
        int count=0;
        for(int i=0; i<temp.size(); i++){
            if(temp[i]=='1'){
                count++;
            }
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        vector<vector<int>>a;
        vector<int>temp;
        int curr=-1;
        for(int i=0; i<nums.size(); i++){
            if(temp.size()==0){
                temp.push_back(nums[i]);
                curr=check(nums[i]);
            }
            else{
                if(curr==check(nums[i])){
                    temp.push_back(nums[i]);
                }
                else{
                    sort(temp.begin(), temp.end());
                    if(temp[temp.size()-1]>nums[i]){
                        return false;
                    }
                    else{
                        a.push_back(temp);
                        temp.clear();
                        temp.push_back(nums[i]);
                        curr=check(nums[i]);
                    }
                }
            }
        }
        if(temp.size()!=0){
            sort(temp.begin(), temp.end());
            a.push_back(temp);
        }
        for(int i=1; i<a.size(); i++){
            if(a[i][0]<a[i-1][a[i-1].size()-1]){
                return false;
            }
        }
        return true;
    }
};