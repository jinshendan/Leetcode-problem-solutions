/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL or head->next == NULL or head->next->next == NULL) return head;
        auto odd = head;
        auto even = head->next;
        auto head_even = head->next;
        while (even -> next != NULL and even->next->next != NULL){
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        if (even->next == NULL){
            odd->next = head_even;  
        }
        else {
            odd->next = even->next;
            odd = odd->next;
            odd->next = head_even;  
            even->next = NULL;
        }
        return head;
    }
};