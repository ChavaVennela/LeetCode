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
    int cal(vector<int>a){
        vector<int>a1=a;
        sort(a1.begin(), a1.end());
        unordered_map<int, int>mp;
        int count=0;
        for(int i=0; i<a.size(); i++){
            mp[a[i]]=i;
        }
        for(int i=0; i<a.size(); i++){
            if(a[i]==a1[i]){
                continue;
            }
            int curr=mp[a1[i]];
            mp[a[i]]=curr;
            swap(a[i], a[curr]);
            count++;
        }
        return count;
    }
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int curr=q.size();
            vector<int>a;
            for(int i=0; i<curr; i++){
                TreeNode* temp=q.front();
                q.pop();
                a.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans+=cal(a);
        }
        return ans;
    }
};