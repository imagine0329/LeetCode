class MyHashMap {
private:
    class Node {
    public:
        int key, val;
        Node* next;
        Node(int key, int val, Node* next) {
            this->key = key;
            this->val = val;
            this->next = next;
        }
    };
    
    const static int size = 19997;
    const static int mult = 12582917;
    
    Node* data[size] = {nullptr};
    
public:
    MyHashMap() {
        
    }
    
    int hash(int key) {
        return (int)((long)key * mult % size);
    }
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, value, data[h]);
        data[h] = node;
    }
    
    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        while(node) {
            if(node->key == key) return node->val;
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if(!node) return;
        if(node->key == key) data[h] = node->next;
        else {
            while(node->next) {
                if(node->next->key == key) {
                    node->next = node->next->next;
                    return;
                }
                node = node->next;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */