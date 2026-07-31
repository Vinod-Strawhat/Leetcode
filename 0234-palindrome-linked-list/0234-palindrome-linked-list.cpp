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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr){
            return false;
        }
        if(head->next ==nullptr){
            return true;
        }
        vector<int> check;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        check.push_back(curr->val);
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=next;
            if(curr!=nullptr)
                check.push_back(curr->val);
        }
        head=prev;
        ListNode* temp=head;
        int i=0;
        while(temp!=nullptr){
            if(check[i]!=temp->val){
                return false;
            }
            temp=temp->next;
            i++;
        }
        return true;


    }
};