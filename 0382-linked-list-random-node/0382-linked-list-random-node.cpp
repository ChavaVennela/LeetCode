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
    ListNode* head1;
    Solution(ListNode* head) {
        head1=head;
    }
    
    int getRandom() {
        double scope=1.0;
        int val1=0;
        ListNode* curr=head1;
        while(curr!=NULL){
            double ran=((double)random()/(double)RAND_MAX);
            if(ran<1.0/scope){
                val1=curr->val;
            }
            scope++;
            curr=curr->next;
        }
        return val1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */