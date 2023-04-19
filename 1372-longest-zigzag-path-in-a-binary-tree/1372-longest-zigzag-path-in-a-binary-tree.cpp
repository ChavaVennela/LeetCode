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
    int longestZigZag(TreeNode* root) {
        int max=1;
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {1, 0}});
        q.push({root, {1, 1}});
        while(!q.empty()){
            pair<TreeNode*, pair<int, int>>temp=q.front();
            pair<int, int>temp1=temp.second;
            q.pop();
            if(temp1.second==0 && temp.first->left != NULL){
                q.push({temp.first->left, {temp1.first+1, 1}});
                if(temp1.first+1>max){
                    max=temp1.first+1;
                }
                q.push({temp.first->left, {1, 0}});
            }
            else if(temp1.second==1 && temp.first->right!=NULL){
                q.push({temp.first->right, {temp1.first+1, 0}});
                if(temp1.first+1>max){
                    max=temp1.first+1;
                }
                q.push({temp.first->right, {1, 1}});
            }
        }
        return max-1;
    }
};