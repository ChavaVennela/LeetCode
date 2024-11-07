struct Node{
    int key, val;
    Node* prev;
    Node* next;
    Node(int key, int val){
        this->key = key;
        this->val=val;
        prev=nullptr;
        next=nullptr;
    }
};
class LRUCache {
public:
    unordered_map<int, Node*>a;
    int cap;
    Node* head=new Node(-1, -1);
    Node* tail=new Node(-1, -1);
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(a.find(key)==a.end()){
            return -1;
        }
        Node* temp=a[key];
        int ans=temp->val;
        remove(temp);
        Node* nod=new Node(key, ans);
        add(nod);
        a[key]=nod;
        return ans;
    }
    
    void put(int key, int value) {
        if(a.find(key)!=a.end()){
            Node* temp=a[key];
            remove(temp);
        }
        else{
            if(a.size()==cap){
                int key1=head->next->key;
                remove(head->next);
                a.erase(key1);
            }
        }
        Node* nod = new Node(key, value);
        a[key]=nod;
        add(nod);
    }
    
    void add(Node* a){
        Node* prevend=tail->prev;
        prevend->next=a;
        a->prev=prevend;
        a->next=tail;
        tail->prev=a;
    }
    
    void remove(Node* a){
        Node* previous=a->prev;
        Node* nex=a->next;
        previous->next=nex;
        nex->prev=previous;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */