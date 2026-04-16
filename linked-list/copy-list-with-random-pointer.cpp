/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        temp = head;
        Node* dummy = new Node(0);
        Node* copy = dummy;

        while (temp) {
            copy->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            copy = copy->next;
        }

        return dummy->next;
    }
};