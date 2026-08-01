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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }if(k>count){
        k=k%count;
        }
        while(k>0){
            ListNode* prev=head;
            ListNode* end=head;
            while(end->next!=nullptr){
                prev=end;
                end=end->next;
            }
            prev->next=nullptr;
            end->next=head;
            head=end;
            k--;
        }
        return head;
    }
};