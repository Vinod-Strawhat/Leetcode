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
    ListNode* removeNodes(ListNode* head) {
        stack<int> s;
        vector<int> arr;
        while(head!=nullptr){
            arr.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && arr[i]>s.top()){
                s.pop();
            }
            s.push(arr[i]);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        for(int i=0;i<ans.size();i++){
            ListNode* newnode=new ListNode(ans[i]);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};