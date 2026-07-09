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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode dummy(-1);
        ListNode*temp=&dummy;
        ListNode*curr=head->next;
        ListNode*prev=head;
        while(curr!=NULL){
            if(curr->val!=prev->val){
                temp->next=prev;
                temp=temp->next;
                prev=prev->next;
                curr=curr->next;
            }
            else{
                while(curr!=NULL && curr->val==prev->val ){
                    curr=curr->next;
                }
                if(curr==NULL) {
                    temp->next=NULL;
                    return dummy.next;
                };
                prev=curr;
                curr=curr->next;
            }
        }
        temp->next=prev;
        return dummy.next;

    }
};