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
    int count=0;
    pair<int, int> check(TreeNode* root){
        if(root==NULL){
            return {0, 0};
        }
        pair<int, int> left=check(root->left);
        pair<int, int> right=check(root->right);
        int count1=left.first+right.first+1;
        int val=left.second+right.second+root->val;
        if(val/count1 ==root->val){
            count++;
        }
        return {count1, val};
    }
    int averageOfSubtree(TreeNode* root) {
        check(root);
        return count;
    }
};