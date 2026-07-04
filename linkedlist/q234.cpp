class Solution {
public:
    ListNode* front; // pointer to track from the start

    bool recursivelyCheck(ListNode* current) {
        if (current == NULL) return true;

        // Go to the end
        if (!recursivelyCheck(current->next)) {
            return false;
        }

        // Compare front and current
        if (front->val != current->val) {
            return false;
        }

        // Move front forward
        front = front->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        front = head;
        return recursivelyCheck(head);
    }
};