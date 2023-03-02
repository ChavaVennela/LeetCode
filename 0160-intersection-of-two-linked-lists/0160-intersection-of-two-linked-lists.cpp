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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>a;
        while(headA){
            a.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(a.find(headB)==a.end()){
                headB=headB->next;
            }
            else{
                return headB;
            }
        }
        return NULL;
    }
};