class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        priority_queue<int>a;
        int count=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                count++;
            }
            else{
                a.push(count);
                count=1;
            }
        }
        a.push(count);
        while(a.size()>1){
            int temp1=a.top();
            a.pop();
           int temp2=a.top();
            a.pop();
            temp1--;
            temp2--;
            if(temp1!=0){
                a.push(temp1);
            }
            if(temp2!=0){
                a.push(temp2);
            }
        }
        if(a.size()==0){
            return 0;
        }
        return a.top();
    }
};