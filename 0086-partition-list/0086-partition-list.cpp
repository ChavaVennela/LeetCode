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
    ListNode* partition(ListNode* head, int x) {
        vector<int>ltemp;
        vector<int>rtemp;
        while(head!=NULL){
            if(head->val<x){
                ltemp.push_back(head->val);
            }
            else{
                rtemp.push_back(head->val);
            }
            head=head->next;
        }
        ListNode* temp=new ListNode();
        ListNode* temp1=temp;
        for(int i=0; i<ltemp.size(); i++){
            ListNode* temp2=new ListNode(ltemp[i]);
            temp->next=temp2;
            temp=temp->next;
        }
        for(int i=0; i<rtemp.size(); i++){
            ListNode* temp2=new ListNode(rtemp[i]);
            temp->next=temp2;
            temp=temp->next;
        }
        return temp1->next;
    }
};