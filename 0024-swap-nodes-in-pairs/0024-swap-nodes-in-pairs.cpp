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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead=head->next;
        ListNode* ptr=head;
        ListNode* prev=NULL;
        while(ptr!=NULL && ptr->next!=NULL){
            ListNode* temp=ptr->next->next;
            ListNode* temp1=ptr->next;
            temp1->next=ptr;
            ptr->next=temp;
            if(prev!=NULL){
                prev->next=temp1;
            }
            prev=ptr;
            ptr=ptr->next;
        }
        return newHead;
    }
};