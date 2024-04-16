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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            return new TreeNode(val, root, NULL);
        }
        TreeNode* temp=root;
        queue<pair<TreeNode*, int>>q;
        q.push({temp, 1});
        while(!q.empty()){
            pair<TreeNode*, int>topval=q.front();
            q.pop();
            if(topval.second>depth-1){
                break;
            }
            else if(topval.second<depth-1){
                if(topval.first->left!=NULL){
                    q.push({topval.first->left, topval.second+1});
                }
                if(topval.first->right!=NULL){
                    q.push({topval.first->right, topval.second+1});
                }
            }
            else{
                TreeNode* templeft=new TreeNode(val);
                TreeNode* tempright=new TreeNode(val);
                if(topval.first->left!=NULL){
                    templeft->left=topval.first->left; 
                }
                if(topval.first->right!=NULL){
                    tempright->right=topval.first->right;
                }
                topval.first->left=templeft;
                topval.first->right=tempright;
            }
        }
        return root;
    }
};