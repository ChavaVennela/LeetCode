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
    int findBottomLeftValue(TreeNode* root) {
        int ans=root->val, hei=0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*, int>temp=q.front();
            q.pop();
            if(temp.second>hei){
                ans=temp.first->val;
                hei=temp.second;
            }
            if(temp.first->left!=NULL){
                q.push({temp.first->left, temp.second+1});
            }
            if(temp.first->right!=NULL){
                q.push({temp.first->right, temp.second+1});
            }
        }
        return ans;
    }
};