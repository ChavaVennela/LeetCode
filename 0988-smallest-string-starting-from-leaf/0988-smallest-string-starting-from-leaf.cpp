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
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>>q;
        string ans="", alpha="abcdefghijklmnopqrstuvwxyz", ini="";
        q.push({root, ini+alpha[root->val]});
        while(!q.empty()){
            pair<TreeNode*, string>temp=q.front();
            q.pop();
            if(temp.first->left==NULL && temp.first->right==NULL){
                if(ans==""){
                    reverse(temp.second.begin(), temp.second.end());
                    ans=temp.second;
                }
                else{
                    reverse(temp.second.begin(), temp.second.end());
                    if(ans>temp.second){
                        ans=temp.second;
                    }
                }
            }
            else{
                if(temp.first->left!=NULL){
                    q.push({temp.first->left, temp.second+alpha[temp.first->left->val]});
                }
                if(temp.first->right!=NULL){
                    q.push({temp.first->right, temp.second+alpha[temp.first->right->val]});
                }
            }
        }
        return ans;
    }
};