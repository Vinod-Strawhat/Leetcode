/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(true){
            
            
            slow=slow->next;
            if(fast->next!=nullptr){
            fast=fast->next->next;}
            else{
                return false;
            }
            if(slow==nullptr || fast==nullptr){
                return false;
            }
            if(&slow->val==&fast->val){
                return true;
            }
        }
        return false;
    }
};