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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* secondHead = split(head);
        ListNode* sortHead = sortList(head);
        ListNode* sortSecondHead = sortList(secondHead);

        return merge(sortHead, sortSecondHead);
    }

    ListNode* split(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* res = slow->next;
        slow->next = nullptr;

        return res;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* res = temp;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        temp->next = l1 ? l1 : l2;

        return res->next;
    }
};