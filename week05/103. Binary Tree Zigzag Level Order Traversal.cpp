//approach: BFS
//TC: O(n)
//MC: O(n), n=n is the number of nodes in the tree

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == NULL) {
            return {};
        }

        queue<TreeNode *> Q;
        vector<vector<int>> zigzag;
        bool reverse = false;

        Q.push(root);

        while (!Q.empty()) {

            int len = Q.size();
            vector<int> level(len);

            for (int i = 0; i < len; ++i) {
                TreeNode *curr = Q.front();
                Q.pop();

                if (reverse) {
                    level[level.size() - 1 - i] = curr -> val;
                }
                else {
                    level[i] = curr -> val;
                }

                if(curr -> left != NULL)
                {
                    Q.push(curr -> left);
                }

                if (curr->right != NULL)
                {
                    Q.push(curr -> right);
                }
            }
            reverse = !reverse;
            zigzag.push_back(level);
        }

        return zigzag;
    }
};
