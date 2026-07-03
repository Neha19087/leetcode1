// we have to find the starting point of a cycle in the linked list 
//we can maintain a hashtable and store pointers to each node
//if pointer repeats that is the starting point of cycle
// time complexity will be O(n) if unordered map and O(nlogn) if ordered map
//space complexity will be O(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mpp;
        if(head==NULL || head->next==NULL) return NULL;
        ListNode*temp=head;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()){
                return temp;
            }
            mpp[temp]++;
            temp=temp->next;
        }
        return NULL;
    }
};
// another method is to use hare and tortoise method(fast and slow pointers)
//let distance from start to beginning of cycle =l1
// distance from beginning of cycle to meeting point =l2
// cycle length =c
//when slow and fast meet 
// slow travelled= l1+l2
// fast travelled= l1+l2+nC
// as fast moves twice: 2(l1+l2)= l1+l2+nc
// L1+l2=nc
// l1=nc-l2
//The distance from head to cycle start==Is equal to the distance from meeting point to cycle start 
//thus entry and slow pointer always meet at beginning of cycle
// time complexity will be O(n) and space complexity constant
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode*entry=head;
                while(entry!=slow){
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }
        }
        return NULL;
        
    }
};