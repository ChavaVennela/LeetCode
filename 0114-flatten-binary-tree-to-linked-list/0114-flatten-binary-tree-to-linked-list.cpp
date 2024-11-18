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
    TreeNode* flat(TreeNode* root){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return root;
        }
        if(root->left==NULL){
            TreeNode* temp=flat(root->right);
            root->right=temp;
            return root;
        }
        else{
            TreeNode* temp=flat(root->left);
            TreeNode* temp1=flat(root->right);
            root->right=temp;
            root->left=NULL;
            while(temp!=NULL){
                if(temp->right==NULL){
                    temp->right=temp1;
                    break;
                }
                temp=temp->right; 
            }
            return root;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        root=flat(root);
    }
};