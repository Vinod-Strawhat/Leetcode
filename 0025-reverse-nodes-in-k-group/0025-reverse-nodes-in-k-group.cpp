class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* nextnode = head;

        while (nextnode) {

            ListNode* precnextnode = prev;

            int cnt = k;

            while (cnt > 0 && precnextnode) {
                precnextnode = precnextnode->next;
                cnt--;
            }

            if (precnextnode == nullptr)
                break;

            nextnode = precnextnode->next;

            precnextnode->next = nullptr;

            ListNode* temp = prev->next;

            prev->next = reverseList(temp);

            temp->next = nextnode;

            prev = temp;

            nextnode = prev->next;
        }

        return dummy->next;
    }
};