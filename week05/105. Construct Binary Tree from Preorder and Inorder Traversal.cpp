//TC: O(n), n = max(inorder length, preorder length)
//MC: O(h), h = max(inorder length, preorder length)

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.empty())
            return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        int split = find (inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();


        vector<int> left_In (inorder.begin(), inorder.begin() + split);
        int left_In_len = left_In.size();
        vector<int> left_Pre (preorder.begin() + 1, preorder.begin() + left_In_len + 1);


        vector<int> right_Pre (preorder.begin() + left_In_len + 1, preorder.end());
        vector<int> right_In (inorder.begin() + split + 1, inorder.end());


        root -> left = buildTree(left_Pre, left_In);
        root -> right = buildTree(right_Pre, right_In);


        return root;
    }
};
