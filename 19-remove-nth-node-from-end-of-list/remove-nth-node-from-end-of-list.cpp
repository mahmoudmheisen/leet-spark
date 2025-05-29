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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return head;
        if (!head->next)
            return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* leader = dummy;
        ListNode* trailer = dummy;

        for (int i = 0; i < n; i++) {
            leader = leader->next;
        }
        
        while(leader && leader->next) {
            leader = leader->next;
            trailer = trailer->next;
        }

        ListNode* temp = trailer->next;
        trailer->next = trailer->next->next;
        temp->next = nullptr;

        return dummy->next;
    }
};