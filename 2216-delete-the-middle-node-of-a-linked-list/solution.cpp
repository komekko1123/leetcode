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
    ListNode* deleteMiddle(ListNode* head) {
      ListNode *slow = head->next, *fast = nullptr, *previous = head;
      if( slow == nullptr){
        head = nullptr;
        return head;
      } // if
      else if( slow->next == nullptr){
        head->next = nullptr;
        slow = nullptr;
        return head;
      } // 

      fast = slow->next;
      while(fast != nullptr && fast->next != nullptr){
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
      } // while   

      previous->next = slow->next; 
      slow->next = nullptr;
      slow = nullptr;       
      return head;
    }
};
