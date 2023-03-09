/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* a=head;
        ListNode* b=head;
        if(a==NULL){
            return a;
        }
        b=b->next;
        if(b==NULL){
            return b;
        }
        b=b->next;
        if(b==NULL){
            return b;
        }
        a=a->next;
        while(a!=b){
            a=a->next;
            b=b->next;
            if(b==NULL){
                return b;
            }
            b=b->next;
            if(b==NULL){
                return b;
            }
        }
        b=head;
        while(a!=b){
            a=a->next;
            b=b->next;
        }
        return b;
    }
};