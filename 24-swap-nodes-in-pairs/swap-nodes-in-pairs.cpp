class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if (!head || !head->next) return head;
      
      ListNode* first = head;
      ListNode* second = head->next;
      head = head->next;
      ListNode* prev = first;
      
      while (second) {
        prev->next = second;
        
        // swap
        ListNode* temp = second->next;
        second->next = first;
        first->next = temp;
        
        prev = first;
        first = first->next;
        if (second->next && second->next->next) second = second->next->next->next;
        else break; 
      }
      
      return head;        
    }
};








