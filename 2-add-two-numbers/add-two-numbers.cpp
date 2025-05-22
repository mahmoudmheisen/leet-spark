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

        int remainder = 0;
        while(l1 || l2) {
            int l1V = l1 ? l1->val : 0;
            int l2V = l2 ? l2->val : 0;
            int sum = l1V + l2V + remainder;

            if(sum >= 10) {
                int temp = sum % 10;
                remainder = sum / 10;
                sum = temp;
            } else {
                remainder = 0;
            }

            current->next = new ListNode(sum);

            current = current->next;

            l1 = l1 ? l1->next: nullptr;
            l2 = l2 ? l2->next: nullptr;
        }

        if(remainder) {
            current->next = new ListNode(remainder);
        }

        return res->next;
    }
};
