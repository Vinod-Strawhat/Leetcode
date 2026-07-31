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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* start = &dummy;
        for (int i = 1; i < left; i++) {
            start = start->next;
        }

        ListNode* r_start = start->next;
        ListNode* r_end = r_start;
        for (int i = left; i < right; i++) {
            r_end = r_end->next;
        }

        ListNode* end = r_end->next;
        start->next = nullptr;
        r_end->next = nullptr;
        ListNode* newHead = reverseList(r_start);
        start->next = newHead;
        r_start->next = end;

        return dummy.next;
    }
};