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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr  || head->next==nullptr){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* end = head;
        while(end->next!=nullptr){
            end=end->next;
        }
        ListNode* temp = head;
        ListNode* prev=dummy;
        ListNode* tail=end;
        while(temp!=tail){
            if(temp->val >= x){
                prev->next=temp->next;
                temp->next=nullptr;
                end->next=temp;
                end=end->next;
                temp=prev->next;
                
            }
            else{
            temp=temp->next;
            prev=prev->next;
            }
        }
        if(temp->val >= x && temp->next!=nullptr){
            prev->next=temp->next;
            temp->next=nullptr;
            end->next=temp;
            end=end->next;
            temp=prev->next;
        }

        return dummy->next;
    }
};