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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int rem=cnt-n;
        if(rem==0){
            temp=head;
            head=head->next;
            temp->next=NULL;
            return head;
        }
        temp=head;
        ListNode*prev=NULL;
        while(rem!=0){
            rem--;
            prev=temp;
            temp=temp->next;
        }
        prev->next=prev->next->next;
        temp->next=NULL;
        return head;
        
    }
};