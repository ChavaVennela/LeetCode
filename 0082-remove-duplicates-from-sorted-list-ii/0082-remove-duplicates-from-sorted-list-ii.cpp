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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int>a;
        while(head!=NULL){
            a[head->val]++;
            head=head->next;
        }
        ListNode* ans=new ListNode(0);
        ListNode* check=ans;
        for(auto it=a.begin(); it!=a.end(); it++){
            if(it->second==1){
                ListNode* temp=new ListNode(it->first);
                ans->next=temp;
                ans=ans->next;
            }
        }
        return check->next;
    }
};