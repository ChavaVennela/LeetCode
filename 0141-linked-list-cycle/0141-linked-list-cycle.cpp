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
    bool hasCycle(ListNode *head) {
       set<ListNode *>a;
        ListNode *safe=new ListNode;
        safe=head;
        bool ans=false;
        while(safe){
            if(a.find(safe) != a.end()){
                ans=true;
                break;
            }
            a.insert(safe);
            safe=safe->next;
        }
        return ans;
    }
};