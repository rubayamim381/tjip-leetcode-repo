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

//TC: O(n), n=the number of nodes in the tree
//MC: O(1)

class Solution {
public:
    bool isMirror(TreeNode* left_root, TreeNode* right_root) {
        if (!left_root && !right_root)
            return true;
        if (!left_root || !right_root)
            return false;

        return left_root -> val == right_root -> val
                && isMirror(left_root -> right, right_root -> left)
                && isMirror(left_root -> left, right_root -> right);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

};
