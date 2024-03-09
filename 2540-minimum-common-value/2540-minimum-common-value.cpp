class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        while(i<nums1.size() && nums1[i]<nums2[nums2.size()-1]){
            if(nums1[i]==nums2[nums2.size()-1]){
                return nums1[i];
            }
            i++;
        }
        while(j<nums2.size() && nums2[j]<nums1[nums1.size()-1]){
            if(nums2[j]==nums1[nums1.size()-1]){
                return nums2[j];
            }
            j++;
        }
        return -1;
    }
};