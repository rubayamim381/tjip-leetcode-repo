// Time:  O(n)
// Space: O(logn)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    TreeNode *Helper(vector<int> &nums, int start, int end) {
        if (start <= end) {
            int mid = start + (end - start) / 2;
            TreeNode *node = new TreeNode(nums[mid]);
            node->left = Helper(nums, start, mid - 1);
            node->right = Helper(nums, mid + 1, end);
            return node;
        }
        return nullptr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Helper(nums, 0, nums.size() - 1);
    }

};
