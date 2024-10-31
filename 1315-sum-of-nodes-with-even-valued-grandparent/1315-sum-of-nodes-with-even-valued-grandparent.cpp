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
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*, vector<int>>>q;
        if(root!=NULL){
            vector<int>a(3, -1);
            if(root->val%2==0){
                a[2]=1;
            }
            q.push({root, a});
        }
        while(!q.empty()){
            pair<TreeNode*, vector<int>>temp=q.front();
            q.pop();
            if(temp.second[0]==1){
                ans+=temp.first->val;
            }
            vector<int>temp1(3, -1);
            temp1[0]=temp.second[1];
            temp1[1]=temp.second[2];
            if(temp.first->left !=NULL){
                if(temp.first->left->val%2==0){
                    temp1[2]=1;
                }
                q.push({temp.first->left, temp1});
            }
            if(temp.first->right !=NULL){
                if(temp.first->right->val%2==0){
                    temp1[2]=1;
                }
                else{
                    temp1[2]=-1;
                }
                q.push({temp.first->right, temp1});
            }
        }
        return ans;
    }
};