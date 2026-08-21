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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return nullptr;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* slowprev=dummy;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr &&  fast->next!=nullptr){
            slowprev=slowprev->next;
            slow=slowprev->next;
            fast=fast->next->next;
        }
        slowprev->next=slow->next;
        return head;
    }
};