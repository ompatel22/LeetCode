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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0,head);

        ListNode* point=dummy;
        ListNode* swap1;
        ListNode* swap2;

        while(point->next!=nullptr && point->next->next!=nullptr){
            swap1=point->next;
            swap2=point->next->next;

            swap1->next=swap2->next;
            swap2->next=swap1;

            point->next=swap2;
            point=swap1;
        }
        return dummy->next;
    }
};