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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        ListNode* h1=list1;
        ListNode* h2=list2;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(h1!=nullptr && h2!=nullptr){
            if(h1->val > h2->val){
                ListNode* newnode=new ListNode(h2->val);
                temp->next=newnode;
                temp=temp->next;
                h2=h2->next;
            }
            else if(h1->val <= h2->val){
                ListNode* newnode=new ListNode(h1->val);
                temp->next=newnode;
                temp=temp->next;
                h1=h1->next;
            }
            
        }
        
            while(h1!=nullptr){
                ListNode* newnode=new ListNode(h1->val);
                temp->next=newnode;
                temp=temp->next;
                h1=h1->next;
            }
            while(h2!=nullptr){
                 ListNode* newnode=new ListNode(h2->val);
                temp->next=newnode;
                temp=temp->next;
                h2=h2->next;
            }
        
        return dummy->next;
    }
};