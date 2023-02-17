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
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>a;
        int ans=INT_MAX;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            a.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            q.pop();
        }
        sort(a.begin(), a.end());
        for(int i=1; i<a.size(); i++){
            ans=min(ans, abs(a[i]-a[i-1]));
        }
        return ans;
    }
};