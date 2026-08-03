class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;   // last non-duplicate node
        ListNode* curr = head;

        while (curr != nullptr) {
            // detect duplicate sequence
            if (curr->next != nullptr && curr->val == curr->next->val) {
                int val = curr->val;

                // skip ALL nodes with this value
                while (curr != nullptr && curr->val == val) {
                    curr = curr->next;
                }

                // connect prev to next non-duplicate
                prev->next = curr;
            } 
            else {
                // move prev normally
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};