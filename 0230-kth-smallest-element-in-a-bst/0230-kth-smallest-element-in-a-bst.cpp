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
    vector<int>a;
    int count;
    void call(TreeNode* root){
        if(a.size()==count){
            return;
        }
        if(root->left!=NULL){
            call(root->left);
        }
        a.push_back(root->val);
        if(root->right!=NULL){
            call(root->right);
        }
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        count=k;
        call(root);
        return a[k-1];
    }
};