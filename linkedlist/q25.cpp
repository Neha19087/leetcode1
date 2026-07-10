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
    ListNode*reverse(ListNode*head){
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp= head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt==k) {
            ListNode*newhead= reverse(head);
            return newhead;
        }
        int n= cnt/k;
        temp=head;
        ListNode*prevtail=new ListNode(-1);
        for(int i=0;i<n;i++){
            ListNode*start=temp;
            int cnt=1;
            while(cnt!=k){
                cnt++;
                temp=temp->next;
            }
            ListNode*tail=temp;
            temp=temp->next;
            tail->next=NULL;
            ListNode*newhead=reverse(start);
            if(i==0){
                head=newhead;
            }
            else{
                prevtail->next=newhead;
            }
            if(i==n-1){
                start->next=temp;
            }
            prevtail=start;

        }
        return head;
         
    }
};