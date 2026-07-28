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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        while(fast!=nullptr){
            if(n<0){
                slow=slow->next;
            }
            fast=fast->next;
            n--;
        }
        ListNode* temp=slow->next;
        slow->next=temp->next;
        delete temp;
        head=dummy->next;
        delete dummy;
        return head;

    }
};