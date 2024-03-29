/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(original);
        q2.push(cloned);
        while(!q1.empty()){
            TreeNode* temp=q1.front();
            TreeNode* temp1=q2.front();
            q1.pop();
            q2.pop();
            if(temp==target){
                return temp1;
            }
            if(temp->left){
                q1.push(temp->left);
                q2.push(temp1->left);
            }
            if(temp->right){
                q1.push(temp->right);
                q2.push(temp1->right);
            }
        }
        return NULL;
    }
};