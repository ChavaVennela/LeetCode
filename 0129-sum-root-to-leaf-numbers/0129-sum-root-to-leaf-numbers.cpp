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
    int sumNumbers(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, root->val});
        while(!q.empty()){
            pair<TreeNode*, int>temp=q.front();
            q.pop();
            if(temp.first->left==NULL && temp.first->right==NULL){
                ans+=temp.second;
                continue;
            }
            if(temp.first->left!=NULL){
                q.push({temp.first->left, (temp.second*10)+temp.first->left->val});
            }
            if(temp.first->right!=NULL){
                q.push({temp.first->right, (temp.second*10)+temp.first->right->val});
            }
        }
        return ans;
    }
};