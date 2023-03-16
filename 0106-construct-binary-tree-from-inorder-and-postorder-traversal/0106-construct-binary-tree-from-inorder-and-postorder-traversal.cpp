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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()<1){
            return NULL;
        }
        if(inorder.size()==1){
            TreeNode* root=new TreeNode(inorder[0]);
            return root;
        }
        TreeNode* root=new TreeNode(postorder[postorder.size()-1]);
        int i, j;
        for(i=0; i<inorder.size(); i++){
            if(inorder[i]==postorder[postorder.size()-1]){
                break;
            }
        }
        vector<int>inorderleft, inorderright, postorderleft, postorderright;
        if(i>0){
            inorderleft={inorder.begin(), inorder.begin()+i};
            postorderleft={postorder.begin(), postorder.begin()+i};
        }
        if(i+1<inorder.size()){
            inorderright={inorder.begin()+i+1, inorder.end()};
            postorderright={postorder.begin()+i, postorder.end()-1};
        }
        root->left=buildTree(inorderleft, postorderleft);
        root->right=buildTree(inorderright, postorderright);
        return root;
    }
};