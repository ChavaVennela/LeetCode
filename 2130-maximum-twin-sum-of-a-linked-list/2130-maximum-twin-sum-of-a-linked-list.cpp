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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>a;
        int i;
        while(head!=NULL){
            a.push_back(head->val);
            head=head->next;
        }
        int ans=0;
        for(i=0; i<a.size()/2; i++){
            ans=max(ans, a[i]+a[a.size()-1-i]);
        }
        return ans;
    }
};