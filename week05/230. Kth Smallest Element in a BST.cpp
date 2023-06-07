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


//approach 1: Binary Search
//TC: O(n^2), n=number of nodes
//MC: O(h), h=max(left node, right node)


class Solution {
public:

    int countNodes(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        const int leftNodeCnt = countNodes(root -> left);

        if(leftNodeCnt == k - 1)
            return root -> val;

        if(leftNodeCnt >= k)
            return kthSmallest(root -> left, k);

        return kthSmallest(root -> right, k - 1 - leftNodeCnt);
    }
};



//approach 2: Inorder Traversal
//TC: O(n), n=number of nodes
//MC: O(h), h=max(left node, right node)


class Solution {
public:

    void traverse(TreeNode* root, int k, int& rank, int& smallest_val)
    {
        if (root == NULL)
            return;

        traverse(root -> left, k, rank, smallest_val);

        ++rank;
        if (rank == k)
        {
            smallest_val = root -> val;
            return;
        }

        traverse(root -> right, k, rank, smallest_val);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        int smallest_val = -1;
        int rank = 0;
        traverse(root, k, rank, smallest_val);
        return smallest_val;
    }
};
