class Node{
public:
    int val;
    int key;
    Node* next;
    Node* prev;

    Node(int key,int data){
        this->val = data;
        this->key = key;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    int size = 0;
    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) {
        this->size = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head; 
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->val;
    }

    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

    void insert(Node* node){
        node -> next = head -> next;
        node -> prev = head;

        head -> next -> prev = node;
        head -> next = node;
    }
    
    void put(int key, int value) {
        // if key already exists
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];

            remove(node);
            
            node -> val = value;

            insert(node);
            mp[key] = node;
        }else{
            // create a new node
            Node* node = new Node(key,value);

            insert(node);
            mp[key] = node;

                if(mp.size() > size){
                    Node* lru = tail->prev;

                    remove(lru);
                    mp.erase(lru->key);
                    delete lru;
                }
        }
    }
};
