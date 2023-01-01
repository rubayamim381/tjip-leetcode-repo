//tc: O(n), number of memory blocks
//mc: O(1)

class Solution {
public:

    void deleteNode(ListNode *deleted_node)
    {
        auto nxt = deleted_node -> next;
        *deleted_node = *(deleted_node -> next);
        delete(nxt);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto first = head;
        auto second = head;
        ListNode* prev_node = NULL;

        while(n--)
        {
            first = first -> next;
        }

        while(first)
        {
            first = first -> next;
            prev_node = second;
            second = second -> next;
        }

        if(second -> next)
            deleteNode(second);
        else if(prev_node) prev_node -> next = NULL;
        else return NULL;

        return head;

    }
};
