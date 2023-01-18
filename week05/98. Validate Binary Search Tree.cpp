//TC: O(n), n=number of nodes
//MC: O(1)

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
    bool isValidBST(TreeNode* root, long long L = LLONG_MIN, long long R = LLONG_MAX) {
        if(root == NULL)
            return true;

        if(L >= root -> val || R <= root -> val)
            return false;
        auto lstatus = isValidBST(root -> left, L, root -> val);
        auto rstatus = isValidBST(root -> right, root -> val, R);

        return lstatus && rstatus;
    }
};
