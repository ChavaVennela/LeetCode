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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int>temp=q.front();
            q.pop();
            if(temp.second==ans.size()){
                ans.push_back(temp.first->val);
            }
            else{
                ans[temp.second]=temp.first->val;
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