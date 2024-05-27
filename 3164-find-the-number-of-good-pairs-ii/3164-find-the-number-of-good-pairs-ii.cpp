class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int, int>b;
        for(int j=0; j<nums1.size(); j++){
            for(int i=1; i*i<=nums1[j]; i++){
                if(nums1[j]%i==0 && nums1[j]/i!=i){
                    b[i]++;
                    b[nums1[j]/i]++;
                }
                else if(nums1[j]==i*i){
                    b[i]++;
                }
            }
        }
        long long count=0;
        for(int i=0; i<nums2.size(); i++){
            if(b.find(nums2[i]*k)!=b.end()){
                count+=b[nums2[i]*k];
            }
        }
        return count;
    }
};