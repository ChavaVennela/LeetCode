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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int i, last=0;
        vector<int>track(300, 0);
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        track[0]=1;
        while(!q.empty()){
            pair<TreeNode*, int>temp=q.front();
            q.pop();
            if(temp.first->left!=NULL){
                track[(2*(temp.second+1))-1]=1;
                q.push({temp.first->left, (2*(temp.second+1))-1});
                if(last+1!=(2*(temp.second+1))-1){
                    return false;
                }
                last++;
            }
            if(temp.first->right!=NULL){
                q.push({temp.first->right, 2*(temp.second+1)});
                track[2*(temp.second+1)]=1;
                if(last+1!=2*(temp.second+1)){
                    return false;
                }
                last++;
            }
        }
        return true;
    }
};