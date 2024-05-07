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
    ListNode* removeNodes(ListNode* head) {
        vector<int>a;
        vector<int>b;
        while(head!=NULL){
            a.push_back(head->val);
            head=head->next;
        }
        b.push_back(a[a.size()-1]);
        int currmax=a[a.size()-1];
        for(int i=a.size()-2; i>=0; i--){
            if(a[i]>=currmax){
                b.push_back(a[i]);
                currmax=a[i];
            }
        }
        ListNode* start=new ListNode(-1);
        ListNode* start1=start;
        for(int i=b.size()-1; i>=0; i--){
            ListNode* temp=new ListNode(b[i]);
            start->next=temp;
            start=start->next;
        }
        return start1->next;
    }
};