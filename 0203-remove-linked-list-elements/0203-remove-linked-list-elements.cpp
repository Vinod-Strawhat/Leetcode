class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* samp = head;

        while(samp != nullptr) {
            if(samp->val == val) {
                prev->next = samp->next;
                samp = samp->next;
            }
            else {
                prev = samp;
                samp = samp->next;
            }
        }

        return dummy->next;
    }
};