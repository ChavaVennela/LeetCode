class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mymap;
        vector<int>ans;
        for(int i=0; i<nums1.size(); i++){
            mymap[nums1[i]]++;
        }
        set<int>a;
        for(int i=0; i<nums2.size(); i++){
            if(mymap.find(nums2[i])!=mymap.end()){
                a.insert(nums2[i]);
            }
        }
        for(auto it=a.begin(); it!=a.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};