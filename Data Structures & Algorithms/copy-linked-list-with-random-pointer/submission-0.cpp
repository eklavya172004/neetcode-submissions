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
        Node* temp = head;

    // inserting copy nodes
        while(temp!= nullptr){
            Node* newNode = new Node(temp->val);

            newNode->next = temp->next;
            temp -> next = newNode; 
            temp = temp->next->next;
        }


// connect random pointers
    temp = head;

        while(temp){
            Node* node = temp->random;
            if(node != nullptr){
                temp->next->random = node -> next;
            }
            temp = temp -> next->next;
        }

// connect next pointers

    temp = head;
        Node* dummy = new Node(0);
        Node* res = dummy;
        

        while(temp){
            res->next = temp -> next;
            temp -> next = temp->next->next;
            res=res->next;
            temp = temp -> next;
        }


        return dummy -> next;
    }
};
