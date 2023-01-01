//tc = O(n), n=number of index
//mc = O(1);

class MyLinkedList {
public:

    class Node{
    public:
        int data;
        Node* next;

        Node(int _data, Node* _next)
        {
            data = _data;
            next = _next;
        }
    };

    Node* head;
    int len;
    const static int DUMMYVAR = INT_MIN;

    //[DUMMYVAR, NULL]
    MyLinkedList() {
        len = 0;
        head = new Node(DUMMYVAR, NULL);

    }

    //[DUMMYVAR, 1] -> [1, addr(2)] -> [2, addr(3)] -> [3, 0]
    int get(int index) {

        if(index < 0 || index >= len) return -1;

        auto cur_node = head -> next;
        while(index--)
        {
            cur_node = cur_node -> next;
        }

        return cur_node -> data;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(len, val);
    }

    //[DUMMYVAR, 1] -> [1, addr(2)] -> [2, addr(4)] -> [4, 0]
    //addAtIndex(3, 3)
    //[DUMMYVAR, 1] -> [1, addr(2)] -> [2, addr(3)] -> [3, 0]  [4, 0]
    //[DUMMYVAR, 1] -> [1, addr(2)] -> [2, addr(3)] -> [3, addr(4)] -> [4, 0]

    void addAtIndex(int index, int val) {

        if(index < 0 || index > len) return;

        auto cur_node = head;

        //if there has multiple node
        while(index--)
        {
            cur_node = cur_node -> next;
        }

        //else
        auto nxt_node = cur_node -> next;
        cur_node->next = new Node(val, NULL);
        cur_node -> next -> next = nxt_node;
        len++;
    }

//[DUMMYVAR, 1] -> [1, addr(2)] -> [2, addr(3)] -> [3, 0]
//[DUMMYVAR, 1] -> [1, addr(3)] -> [3, 0]

    void deleteAtIndex(int index) {

        if(index < 0 || index >= len) return;

        auto cur_node = head;
        while(index--)
        {
            cur_node = cur_node -> next;
        }

        auto nxt = cur_node -> next;
        cur_node -> next = nxt -> next;
        delete(nxt);
        len--;
    }
};
