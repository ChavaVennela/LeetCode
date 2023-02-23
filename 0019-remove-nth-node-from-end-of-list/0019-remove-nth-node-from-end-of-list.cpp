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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0, i;
        ListNode* next2;
        ListNode* next1;
        next1=head;
        while(next1 != NULL){
            next1 = next1->next;
            count++;
        }
        next2=head;
        for(i=0; i<count-n; i++){
            if(i==count-n-1){
                ListNode* next3=head;
                next3 = next3->next;
                head->next = next3->next;
            }
            else{
                //cout<<head->val<<" ";
                head = head->next;
            }
        }
        if(count == n){
            return next2->next;
        }
        //cout<<count<<endl;
        return next2;
    }
};