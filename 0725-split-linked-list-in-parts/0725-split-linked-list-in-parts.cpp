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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count=0, check=0, check1, i=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        vector<ListNode*>a;
        ListNode* poi=head;
        check1=count/k;
        check=count%k;
        int st;
        for(i=0; i<k; i++){
            a.push_back(poi);
            if(poi!=NULL){ 
                if(check>0){
                    st=0;
                    check--;
                }
                else{
                    st=1;
                }
                head=poi;
                for(int j=st; j<check1; j++){
                    head=head->next;
                    if(head==NULL){
                        break;
                    }
                }
                if(head==NULL){
                    poi=NULL;
                }
                else{
                    poi=head->next;
                    head->next=NULL;
                }
            }
        }
        return a;
    }
};