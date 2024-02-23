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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        vector<int>count;
        vector<double>total;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int>temp=q.front();
            q.pop();
            if(temp.second <count.size()){
                count[temp.second]++;
                total[temp.second]+=temp.first->val;
            }
            else{
                count.push_back(1);
                total.push_back(temp.first->val);
            }
            if(temp.first->left != NULL){
                q.push({temp.first->left, temp.second+1});
            }
            if(temp.first->right !=NULL){
                q.push({temp.first->right, temp.second+1});
            }
        }
        for(int i=0; i<total.size(); i++){
            ans.push_back((double)total[i]/count[i]);
        }
        return ans;
    }
};