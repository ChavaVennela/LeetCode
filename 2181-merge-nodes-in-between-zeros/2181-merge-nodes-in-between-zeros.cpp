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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>a;
        int temp=0;
        while(head){
            if(head->val==0){
                a.push_back(temp);
                temp=0;
            }
            else{
                temp+=head->val;
            }
            head=head->next;
        }
        ListNode* ans=new ListNode(a[0]);
        ListNode* temp1=ans;
        for(int i=1; i<a.size(); i++){
            temp1->next=new ListNode(a[i]);
            temp1=temp1->next;
        }
        return ans->next;
    }
};