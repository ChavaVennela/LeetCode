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
    bool check(vector<int>b){
        int odd=0, even=0;
        for(int i=0; i<b.size(); i++){
            if(b[i]!=0){
                if(b[i]%2==0){
                    even++;
                }
                else{
                    odd++;
                }
            }
        }
        if(odd>1){
            return false;
        }
        return true;
    } 
    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0;
        queue<pair<TreeNode*, vector<int>>>q;
        vector<int>a(10, 0);
        a[root->val]++;
        q.push({root, a});
        while(!q.empty()){
            pair<TreeNode*, vector<int>>temp=q.front();
            q.pop();
            if(temp.first->left==NULL && temp.first->right==NULL){
                if(check(temp.second)){
                    count++;
                }
            }
            else{
                if(temp.first->left!=NULL){
                    temp.second[temp.first->left->val]++;
                    q.push({temp.first->left, temp.second});
                    temp.second[temp.first->left->val]--;
                }
                if(temp.first->right!=NULL){
                    temp.second[temp.first->right->val]++;
                    q.push({temp.first->right, temp.second});
                    temp.second[temp.first->right->val]--;
                }
            }
        }
        return count;
    }
};