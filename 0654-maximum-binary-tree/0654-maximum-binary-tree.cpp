/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        else if(nums.size()==1){
            TreeNode* ans=new TreeNode(nums[0]);
            return ans;
        }
        int val=0, pos=0;
        for(int i=0; i<nums.size(); i++){
            val=max(val, nums[i]);
            if(val==nums[i]){
                pos=i;
            }
        }
        TreeNode* ans=new TreeNode(val);
        if(pos!=0){
            vector<int>leftNums(nums.begin(), nums.begin()+pos);
            TreeNode* left=constructMaximumBinaryTree(leftNums);
            ans->left=left;
        }
        if(pos!=nums.size()-1){
            vector<int>rightNums(nums.begin()+pos+1, nums.end());
            TreeNode* right=constructMaximumBinaryTree(rightNums);
            ans->right=right;
        }
        return ans;
    }
};