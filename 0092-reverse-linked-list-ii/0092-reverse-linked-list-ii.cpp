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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* leftprev=dummy;
        ListNode* curr=head;

        for(int i=0;i<left-1;i++){
            leftprev=leftprev->next;
            curr=curr->next;
        }

        ListNode* sublisthead=curr;
        ListNode* prev=nullptr;
        ListNode* nextt;
        for(int i=0;i<(right-left+1);++i){
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        leftprev->next=prev;
        sublisthead->next=curr;

        return dummy->next;
    }
};