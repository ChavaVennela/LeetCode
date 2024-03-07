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
    ListNode* middleNode(ListNode* head) {
        ListNode* test = head;
        int count=0;
        while(test){
            count++;
            test=test->next;
        }
        int i = count/2;
        while(i>0){
            head = head->next;
            i--;
        }
        return head;
    }
};