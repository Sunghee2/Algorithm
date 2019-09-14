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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL, *tmp = result;
        int next = 0, value = 0;
        
        while(l1 || l2 || next) {
            value = next;
            
            if(l1) {
                value += l1 -> val;
                l1 = l1 -> next;
            }
            
            if(l2) {
                value += l2 -> val;
                l2 = l2 -> next;
            }
            
            if(result) {
                tmp -> next = new ListNode(value % 10);
                tmp = tmp -> next;
            } else {
                result = new ListNode(value % 10);
                tmp = result;
            }

            next = value / 10;
        }
        
        return result;
    }
};