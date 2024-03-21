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
    ListNode* reverseList(ListNode* head) {
        int count=0, i;
        ListNode *find=new ListNode();
        find= head;
        while(find){
            count++;
            find=find->next;
        }
        ListNode *ans=new ListNode();
        ListNode *newl=ans;
        while(count != 0){
            ListNode *hello=new ListNode();
            hello=head;
            i=0;
            while(hello && i< count-1){
                hello=hello->next;
                i++;
            }
            int a=hello->val;
            newl->next=new ListNode(a);
            newl=newl->next;
            count--;
        }
        return ans->next;
    }
};