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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=nullptr){
            while(prev->val == curr->val){
                if(curr->next==nullptr){
                    prev->next=nullptr;
                    break;
                }
                else{
                    ListNode* next=curr->next;
                    curr->next==nullptr;
                    prev->next=next;
                    curr=next;
                }
            }
            prev=prev->next;
            curr=curr->next;
        }
        return head;
    }
};