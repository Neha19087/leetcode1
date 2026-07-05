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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode*left=l1;
        ListNode*right=l2;
        ListNode*curr=&dummy;
        int carry=0;
        while(left!=NULL || right!=NULL|| carry!=0){
            int sum=carry;
            if(left!=NULL){
                sum+=left->val;
                left=left->next;
            }
            if(right!=NULL){
                sum+=right->val;
                right=right->next;
            }
            carry=sum/10;
            curr->next= new ListNode(sum%10) ;
            curr=curr->next;
        }
        return dummy.next;
    }
};