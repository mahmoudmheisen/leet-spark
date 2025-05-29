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
        if (!head->next)
            return nullptr;

        ListNode* leader = head;
        ListNode* trailer = head;

        int k = 0;
        while (leader->next) {
            k++;
            leader = leader->next;
            if (k > n)
                trailer = trailer->next;
        }

        if (k + 1 == n)
            return head->next;

        ListNode* temp = trailer->next;
        trailer->next = trailer->next->next;
        temp->next = nullptr;

        return head;
    }
};