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
        if(head==nullptr || head->next==nullptr){
            return head;
        }
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
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        int maxi=0;
        int add=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int half = count/2;
        ListNode* a=head;
        while(half>1){
            a=a->next;
            half--;
        }
        ListNode* newhead=a->next;
        a->next=nullptr;
        newhead=reverseList(newhead);
        ListNode* temp2 = head;
        while(temp2!=nullptr || newhead!=nullptr){
            add=temp2->val + newhead->val;
            maxi=max(maxi,add);
            temp2=temp2->next;
            newhead=newhead->next;
            half--;
        }
        return maxi;
    }
};