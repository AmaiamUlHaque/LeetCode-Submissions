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
        
        ListNode* dummyHeader = new ListNode(); 
        ListNode* current = dummyHeader;

        int carryOver = 0;

        while (l1!=nullptr || l2!=nullptr || carryOver!= 0){ //while a digit exists

            // get current node's values
            int digit1 = (l1 == nullptr)? 0 : l1->val;
            int digit2 = (l2 == nullptr)? 0 : l2->val;
            
            // calculate sum and carry
            int digit3 = digit1+digit2+carryOver;
            carryOver = digit3 / 10;
            digit3 %= 10;

            // create new node for new digit
            current->next = new ListNode(digit3);
            current = current->next;

            // move to next nodes
            if (l1 != nullptr){
                l1 = l1->next;
            }
            if (l2 != nullptr){
                l2 = l2->next;
            }

        }

        ListNode* result = dummyHeader->next;
        delete dummyHeader;
        return result;
    }

};