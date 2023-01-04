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

 //tc= O(mlogk) where m = number of lists elements, k= number of lists
 //mc= O(m)
class Solution {
public:

    ListNode* MergeTwoLists(ListNode* left, ListNode* right)
    {
        ListNode* dummy_head = new ListNode(0);
        ListNode* copy_head = dummy_head;

        while(left and right)
        {
            int vleft = left->val;
            int vright = right->val;

            if(vleft < vright)
            {
                dummy_head -> next = new ListNode(vleft);
                left = left -> next;
            }
            else
            {
                dummy_head -> next = new ListNode(vright);
                right = right -> next;
            }

            dummy_head = dummy_head -> next;
        }

        while(left)
        {
            dummy_head -> next = new ListNode(left -> val);
            dummy_head = dummy_head -> next;
            left = left -> next;
        }

        while(right)
        {
            dummy_head -> next = new ListNode(right -> val);
            dummy_head = dummy_head -> next;
            right = right -> next;
        }

        return copy_head -> next;

    }

    ListNode* helper(int left_list, int right_list, vector<ListNode*>& lists)
    {
        if(left_list > right_list)
            return NULL;
        else if(left_list == right_list)
            return lists[left_list];

        int Mid = (left_list + right_list) / 2;

        auto left = helper(left_list, Mid, lists);
        auto right = helper(Mid+1, right_list, lists);

        return MergeTwoLists(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        return helper(0, lists.size()-1, lists);
    }
};
