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
    int gcd(int a, int b){
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }
        if(a==b){
            return a;
        }
        if(a>b){
            return gcd(a-b,b);
        }
        return gcd(b-a,a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* head1=head;
        while(head->next!=NULL){
            int a=head->val;
            int b=head->next->val;
            ListNode* temp=new ListNode(gcd(a,b), head->next);
            head->next=temp;
            head=head->next;
            head=head->next;
        }
        return head1;
    }
};