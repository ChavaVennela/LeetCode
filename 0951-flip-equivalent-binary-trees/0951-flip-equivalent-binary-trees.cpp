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
    int childCount(TreeNode* root){
        int count=0;
        if(root->left!=NULL){
            count++;
        }
        if(root->right!=NULL){
            count++;
        }
        return count;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL){
            return true;
        }
        if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }
        int count1=childCount(root1), count2=childCount(root2);
        if(count1==count2){
            if(count1==0){
                return true;
            }
            if(count1==1){
                if(root1->left!=NULL){
                    if(root2->left!=NULL){
                        return flipEquiv(root1->left, root2->left);
                    }
                    return flipEquiv(root1->left, root2->right);
                }
                else{
                    if(root2->left!=NULL){
                        return flipEquiv(root1->right, root2->left);
                    }
                    return flipEquiv(root1->right, root2->right);
                }
            }
            if(root1->left->val==root2->left->val){
                return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
            }
            if(root1->left->val==root2->right->val){
                return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
            }
        }
        return false;
    }
};