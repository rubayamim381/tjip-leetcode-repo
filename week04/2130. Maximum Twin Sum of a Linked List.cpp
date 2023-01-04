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

 //approach: dividing the list in two parts and after calculating the maximum sum, reconstruct it
 //tc: O(n), n= number of list elements
 //mc : O(1)

class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode *slow = head, *fast = head;

        //middle to the linked list
        while(fast -> next && fast -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        //slow = middle, fast = null

        ListNode *prev = NULL, *next;
        //reverse action
        while(slow != NULL)
        {
            next = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = next;
        }

        return prev;
    }

    void reconstruct(ListNode *reverseHead)
    {

        ListNode *slow = reverseHead;
        ListNode *prev = NULL, *next;

        //reverse action
        while(slow != NULL)
        {
            next = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = next;
        }
    }

    int pairSum(ListNode* head) {
        int max_sum = 0;

        ListNode *reverseHead = reverse(head);

        while(reverseHead -> next != NULL)
        {
            max_sum = max(reverseHead -> val + head -> val, max_sum);
            reverseHead = reverseHead -> next;
            head = head -> next;
        }

        reconstruct(reverseHead);

        return max_sum;
    }
};
