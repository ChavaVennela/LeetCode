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
    ListNode* oddEvenList(ListNode* head) {
        vector<int>a;
        vector<int>b;
        int i=0;
        while(head){
            if(i==0){
                a.push_back(head->val);
                head=head->next;
                i=1;
            }
            else{
                b.push_back(head->val);
                head=head->next;
                i=0;
            }
        }
        ListNode* ans=new ListNode();
        ListNode* temp=new ListNode();
        ans=temp;
        for(i=0; i<a.size(); i++){
            temp->next=new ListNode(a[i]);
            temp= temp->next;
        }
        for(i=0; i<b.size(); i++){
            temp->next=new ListNode(b[i]);
            temp=temp->next;
        }
        return ans->next;
    }
};