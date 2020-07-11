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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            ListNode **pp = l1->val < l2->val ? &l1 : &l2;
            cur->next = *pp;
            cur = cur->next;
            *pp = (*pp)->next;
        }

        cur->next = l1 == nullptr? l2 : l1;
        
        ListNode *head = dummy->next;
        delete dummy;

        return head;
    }
};