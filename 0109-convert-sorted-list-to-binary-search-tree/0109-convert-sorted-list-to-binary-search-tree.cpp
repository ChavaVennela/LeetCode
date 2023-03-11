/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<string>a;
    void makelis(vector<int>b, int l, int r, int pos){
        if(l>r){
            return;
        }
        if(l==r){
            a[pos]=to_string(b[l]);
            return;
        }
        int mid=l+ceil((float)(r-l)/2);
        a[pos]=to_string(b[mid]);
        makelis(b, l, mid-1, (2*(pos+1))-1);
        makelis(b, mid+1, r, (2*(pos+1)));
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        vector<int>b;
        while(head!=NULL){
            b.push_back(head->val);
            head=head->next;
        }
        a.resize(b.size()*3, "NULL");
        makelis(b, 0, b.size()-1, 0);
        int i=1;
        TreeNode* ans=new TreeNode(stoi(a[0]));
        queue<TreeNode*>q;
        q.push(ans);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(a[i]!="NULL"){
                temp->left=new TreeNode(stoi(a[i]));
                q.push(temp->left);
            }
            i++;
            if(a[i]!="NULL"){
                temp->right=new TreeNode(stoi(a[i]));
                q.push(temp->right);
            }
            i++;
        }
        return ans;
    }
};