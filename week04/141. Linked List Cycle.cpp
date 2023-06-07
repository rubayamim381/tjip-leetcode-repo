
 //aproach 1: using map
 //tc :O(n), n=number of list
 //mc: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map <ListNode*, bool> repeated_node;

        while(head)
        {
            if(repeated_node.count(head) == 1) return true;
            repeated_node[head] = true;
            head = head -> next;
        }

        return false;
    }
};



//approach 2: hare and tortoise cycle finding algorithm
            //or Floyd's Tortoise and Hare Algorithm
//tc: O(n), mc: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != NULL && fast -> next -> next != NULL)
        {

            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) return true;
        }

        return false;
    }
};
