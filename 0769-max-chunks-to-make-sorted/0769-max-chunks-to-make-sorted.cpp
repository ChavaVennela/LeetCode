class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int>a;
        for(int i=0; i<arr.size(); i++){
            if(a.empty() || arr[i]>a.top()){
                a.push(arr[i]);
            }
            else{
                int temp=a.top();
                while(!a.empty() && arr[i]<a.top()){
                    a.pop();
                }
                a.push(temp);
            }
        }
        return a.size();
    }
};