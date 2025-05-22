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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current = new ListNode(0);
        ListNode* res = current;

        int sum = 0, curry = 0;
        while(l1 || l2) {
            int l1V = l1 ? l1->val : 0;
            int l2V = l2 ? l2->val : 0;
            int s = l1V + l2V + curry;

            sum = s % 10;
            curry = s / 10;

            current->next = new ListNode(sum);

            current = current->next;
            l1 = l1 ? l1->next: nullptr;
            l2 = l2 ? l2->next: nullptr;
        }

        if(curry) {
            current->next = new ListNode(curry);
        }

        return res->next;
    }
};
