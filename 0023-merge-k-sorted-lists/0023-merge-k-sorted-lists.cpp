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
        // Recursive Approach 
        ListNode* c1 = list1;
        ListNode* c2 = list2;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        if(c1 == NULL){
            return list2;
        }
        if(c2 == NULL){
            return list1;
        }
        while(c1!=nullptr && c2!=nullptr){
            if(c1->val < c2->val)
            {
                temp->next=c1;
                temp=temp->next;
                c1=c1->next;
            }
            else
            {
                temp->next=c2;
                temp=temp->next;
                c2=c2->next;
            }
        }
        while(c1!=nullptr)
        {
            temp->next=c1;
            temp=temp->next;
            c1=c1->next;
        }
        while(c2!=nullptr)
        {
            temp->next=c2;
            temp=temp->next;
            c2=c2->next;   
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        int count=0;
        while(count<lists.size()){
            ans = mergeTwoLists(ans,lists[count]);
            count++;
        }
        return ans;
    }
};