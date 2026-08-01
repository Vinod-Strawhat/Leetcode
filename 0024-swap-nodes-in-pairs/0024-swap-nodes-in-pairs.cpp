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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* first=head;
        ListNode* second=head->next;
        while(first->next !=nullptr){
            ListNode* next=second->next;
            first->next=next;
            second->next=first;
            prev->next=second;
            prev=first;
            first=prev->next;
            if(first == nullptr || first->next == nullptr)
                break;

            second = first->next;
        }
        return dummy->next;
    }
};