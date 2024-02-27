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
    pair<int, int> calculate(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int, int>leftval, rightval;
        if(root->left !=NULL){
            leftval=calculate(root->left);
        }
        if(root->right!=NULL){
            rightval=calculate(root->right);
        }
        int ansdia=max(leftval.second+rightval.second, max(leftval.first, rightval.first));
        int anshie=max(leftval.second, rightval.second)+1;
        return {ansdia, anshie};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return calculate(root).first;
    }
};