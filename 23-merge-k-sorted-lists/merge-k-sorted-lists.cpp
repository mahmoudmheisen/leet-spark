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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* current = res;

        priority_queue<ListNode*, vector<ListNode*>,
                       decltype([](ListNode* a, ListNode* b) {
                           return a->val > b->val;
                       })>
            minHeap;

        for (ListNode* head : lists) {
            if (head)
                minHeap.push(head);
        }

        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            current->next = minNode;
            current = current->next;
            if (minNode->next)
                minHeap.push(minNode->next);
        }

        return res->next;
    }
};