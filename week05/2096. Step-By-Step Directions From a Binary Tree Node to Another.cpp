//Approach 1: LCA + Build paths using L, R, U
//TC: O(n)
//MC: O(n)


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

#define START (0)
#define END (1)

class Solution {
public:

    TreeNode *findLCA(TreeNode *root, int startVal, int endVal) {

        if (root == nullptr)
            return nullptr;

        TreeNode *left = findLCA(root -> left, startVal, endVal);
        TreeNode *right = findLCA(root -> right, startVal, endVal);

        if (root -> val == startVal || root -> val == endVal)
            return root;

        if(left == nullptr)
            return right;

        if (right == nullptr)
            return left;

        return root;
    }


    TreeNode *findPath(TreeNode *root, string &path, int val, int flag) {
        if (root == nullptr)
            return nullptr;


        if (root -> val == val)
            return root;


        if (flag == START)
            path.push_back('U');
        else
            path.push_back('L');


        TreeNode *left = findPath(root -> left, path, val, flag);

        if (left == nullptr)
             path.pop_back();
        else
             return left;


        if (flag == START)
            path.push_back('U');
        else
            path.push_back('R');


        TreeNode *right = findPath(root -> right, path, val, flag);

        if (right == nullptr)
             path.pop_back();
        else
             return right;

        return nullptr;
    }

    string getDirections(TreeNode *root, int startVal, int endVal) {

        TreeNode *lca = findLCA(root, startVal, endVal);
        string path_to_start, path_to_end;

        findPath(lca, path_to_start, startVal, START);
        findPath(lca, path_to_end, endVal, END);

        return path_to_start + path_to_end;
    }
};
