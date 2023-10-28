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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0){
            return head;
        }
        ListNode* temp=head;
        ListNode* last;
        int count=0, count1=0;
        while(temp!=NULL){
            last=temp;
            temp=temp->next;
            count++;
        }
        if(count==k || (k>count && k%count==0)){
            return head;
        }
        if(k>count){
            k=k%count;
        }
        ListNode* temp2=head;
        ListNode* prev=new ListNode(0, head);
        while(count1<count-k){
            prev=prev->next;
            temp2=temp2->next;
            count1++;
        }
        //ListNode* temp3=new ListNode(temp2->val, temp2->next);
        prev->next=NULL;
        last->next=head;
        return temp2;
        
    }
};