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
    void reorderList(ListNode* head) {
        if(head==nullptr)
            return;
        if(head->next==nullptr)
            return;
        if(head->next->next==nullptr)
            return;
        ListNode* t2=head;
        while(t2->next->next!=nullptr)
            t2=t2->next;
        ListNode* r=t2->next;
        ListNode* l=head;
        ListNode* t1=l->next;
        while(l!=r)
        {
            l->next=r;
            r->next=t1;
            l=t1;
            t1=l->next;
            r=t2;
            t2=t1;
            while(t2!=r && t2->next!=r)
                t2=t2->next;
        }
        l->next=nullptr;
    }
};