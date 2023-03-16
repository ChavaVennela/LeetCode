class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>a;
        vector<int>b;
        int i, j;
        for(i=0; i<nums.size(); i++){
            if(nums[i]<0){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }
        j=0;
        for(i=0; i<nums.size(); i++){
            if(i%2==0){
                nums[i]=b[j];
                j++;
            }
            else{
                nums[i]=a[j-1];
            }
        }
        return nums;
    }
};