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
    ListNode* doubleIt(ListNode* head) {
        vector<int>a;
        ListNode* start=head;
        while(start!=NULL){
            a.push_back(start->val);
            start=start->next;
        }
        int carry=0;
        reverse(a.begin(), a.end());
        for(int i=0; i<a.size(); i++){
            if((a[i]*2)+carry>9){
                a[i]=((a[i]*2)+carry)%10;
                carry=1;
            }
            else{
                a[i]=(a[i]*2)+carry;
                carry=0;
            }
        }
        if(carry>0){
            a.push_back(carry);
        }
        ListNode* start1=new ListNode(-1);
        ListNode* temp=start1;
        for(int i=a.size()-1; i>=0; i--){
            ListNode* temp1=new ListNode(a[i]);
            start1->next=temp1;
            start1=start1->next;
        }
        return temp->next;
    }
};