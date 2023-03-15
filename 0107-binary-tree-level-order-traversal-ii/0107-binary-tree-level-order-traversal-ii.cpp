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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<pair<TreeNode*, int>>q;
        vector<int>temp1;
        ans.push_back(temp1);
        ans[0].push_back(root->val);
        q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int>temp=q.front();
            q.pop();
            if(temp.first->left!=NULL){
                if(ans.size()==temp.second+1){
                    vector<int>temp1;
                    ans.push_back(temp1);
                }
                ans[temp.second+1].push_back(temp.first->left->val);
                q.push({temp.first->left, temp.second+1});
            }
            if(temp.first->right!=NULL){
                if(ans.size()==temp.second+1){
                    vector<int>temp1;
                    ans.push_back(temp1);
                }
                ans[temp.second+1].push_back(temp.first->right->val);
                q.push({temp.first->right, temp.second+1});
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};