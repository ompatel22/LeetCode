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
        stack<ListNode*> st;
        ListNode* curr=head;
        while(curr!=nullptr)
        {
            while(!st.empty() && st.top()->val < curr->val)
            {
                st.pop();
            }
            st.push(curr);
            curr=curr->next;
        }
        ListNode* h1=new ListNode();
        ListNode* temp=h1;
        stack<ListNode*> st2;
        while(!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }  
        while(!st2.empty())
        {
            temp->next=st2.top();
            st2.pop();
            temp=temp->next;
        }
        temp->next=NULL;
        return h1->next;
    
    }
};