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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*>q1;
        stack<TreeNode*>q2;
        vector<vector<int>>ans;
        int ord=0;
        if(root!=NULL){
            q1.push(root);
            vector<int>temp;
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        while(!q1.empty() || !q2.empty()){
            if(ord==0){
                vector<int>temp1;
                while(!q1.empty()){
                    TreeNode* temp=q1.top();
                    if(temp->right!=NULL){
                        q2.push(temp->right);
                        temp1.push_back(temp->right->val);
                    }
                    if(temp->left!=NULL){
                        q2.push(temp->left);
                        temp1.push_back(temp->left->val);
                    }
                    q1.pop();
                }
                if(temp1.size()>0){
                    ans.push_back(temp1);
                }
                ord=1;
            }
            else{
                vector<int>temp1;
                while(!q2.empty()){
                    TreeNode* temp=q2.top();
                    if(temp->left!=NULL){
                        q1.push(temp->left);
                        temp1.push_back(temp->left->val);
                    }
                    if(temp->right!=NULL){
                        q1.push(temp->right);
                        temp1.push_back(temp->right->val);
                    }
                    q2.pop();
                }
                if(temp1.size()>0){
                    ans.push_back(temp1);
                }
                ord=0;
            }
        }
        return ans;
    }
};