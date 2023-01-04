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

 //tc : O(n), n=number of list elements
 //mc : O(n), n=number of list elements for a new list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* first = result;

        while(l1 || l2 || carry)
        {
            int d1 = l1 ? l1 -> val : 0;
            int d2 = l2 ? l2 -> val : 0;
            int sum = d1 + d2 + carry;

            first -> next = new ListNode(sum%10);
            first = first -> next;
            carry = sum/10;

            l1 = l1 ? l1 -> next : NULL;
            l2 = l2 ? l2 -> next : NULL;

        }

        return result -> next;
    }
};
