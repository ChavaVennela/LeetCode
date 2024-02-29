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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int level=0, lastval=-1, direction=1;
        while(!q.empty()){
            pair<TreeNode*, int>temp=q.front();
            q.pop();
            if(temp.second%2==0 && temp.first->val%2==0){
                return false;
            }
            if(temp.second%2!=0 && temp.first->val%2!=0){
                return false;
            }
            if(level==temp.second){
                if(lastval==-1){
                    lastval=temp.first->val;
                }
                else{
                    if(direction==1){
                        if(lastval>=temp.first->val){
                            return false;
                        }
                    }
                    else{
                        if(lastval<=temp.first->val){
                            return false;
                        }
                    }
                    lastval=temp.first->val;
                }
            }
            else{
                level=temp.second;
                direction=(direction+1)%2;
                lastval=temp.first->val;
            }
            if(temp.first->left !=NULL){
                q.push({temp.first->left, temp.second+1});
            }
            if(temp.first->right!=NULL){
                q.push({temp.first->right, temp.second+1});
            }
        }
        return true;
    }
};