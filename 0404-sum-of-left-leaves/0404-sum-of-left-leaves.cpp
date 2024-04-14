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
    int ans;
    void sum(TreeNode* root){
        if(!(root->left || root->right)){
            return;
        }
        else if(root->left){
            TreeNode* child=new TreeNode;
            child=root->left;
            if(!(child->left || child->right)){
                ans=ans+child->val;
            }
            else{
                sum(root->left);
            }
        }
        if(root->right){
            sum(root->right);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        ans=0;
        sum(root);
        return ans;
    }
};