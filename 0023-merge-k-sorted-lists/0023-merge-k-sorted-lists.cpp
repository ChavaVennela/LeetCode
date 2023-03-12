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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int> >pq;
        int i;
        for(i=0; i<lists.size(); i++){
            while(lists[i]){
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        ListNode* temp=new ListNode();
        ListNode* ans=temp;
        while(!pq.empty()){
            ans->next=new ListNode(pq.top());
            pq.pop();
            ans=ans->next;
        }
        return temp->next;
    }
};