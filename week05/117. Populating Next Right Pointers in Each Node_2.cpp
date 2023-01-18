//TC: O(n), n=number of node
//MC: O(l), l=max(left_node, right_node)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(!root)
            return root;

        queue<Node*> qNode;
        qNode.push(root);

        while(!qNode.empty())
        {
            int len = qNode.size();
            for(int i = 0; i < len; i++)
            {
                auto u = qNode.front();
                qNode.pop();

                if( i + 1 < len)
                    u -> next = qNode.front();
                if(u -> left) qNode.push(u -> left);
                if(u -> right) qNode.push(u -> right);
            }
        }

        return root;

    }
};
