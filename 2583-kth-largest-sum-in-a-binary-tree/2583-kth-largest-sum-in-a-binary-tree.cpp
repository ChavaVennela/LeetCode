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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>a;
        queue<pair<TreeNode*, int>>q;
        if(root!=NULL){
            q.push({root, 0});
        }
        while(!q.empty()){
            pair<TreeNode*, int>temp=q.front();
            q.pop();
            if((int)a.size()==temp.second){
                a.push_back(temp.first->val);
            }
            else{
                a[temp.second]+=temp.first->val;
            }
            if(temp.first->left != NULL){
                q.push({temp.first->left, temp.second+1});
            }
            if(temp.first->right != NULL){
                q.push({temp.first->right, temp.second+1});
            }
        }
        if(a.size()<k){
            return -1;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        return a[k-1];
    }
};