class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        set<int>a;
        set<int>b;
        int i, j;
        for(i=0; i<nums1.size(); i++){
            int count=0;
            for(j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    count=1;
                    break;
                }
            }
            if(count==0){
                a.insert(nums1[i]);
            }
        }
        for(i=0; i<nums2.size(); i++){
            int count=0;
            for(j=0; j<nums1.size(); j++){
                if(nums2[i]==nums1[j]){
                    count=1;
                    break;
                }
            }
            if(count==0){
                b.insert(nums2[i]);
            }
        }
        vector<int>a1;
        vector<int>b1;
        for(auto it=a.begin(); it!=a.end(); it++){
            a1.push_back(*it);
        }
        for(auto it=b.begin(); it!=b.end(); it++){
            b1.push_back(*it);
        }
        ans.push_back(a1);
        ans.push_back(b1);
        return ans;
    }
};