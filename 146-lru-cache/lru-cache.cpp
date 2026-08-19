class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k,int v){
        key=k;
        val=v;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int,Node*>mp;
    Node* head,*tail;
    void del(Node* nd){
        Node* a=nd->prev,*b=nd->next;
        nd->prev=NULL;
        nd->next=NULL;
        a->next=b;
        b->prev=a;
    }
    void add(Node* nd){
        Node* nxt=head->next;
        head->next=nd;
        nd->next=nxt;
        nxt->prev=nd;
        nd->prev=head;
    }
    LRUCache(int capacity) {
        cap=capacity;
         head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* nd=mp[key];
            del(nd);
            add(nd);
            return nd->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* nd=mp[key];
            del(nd);
            add(nd);
            nd->val=value;
            return;
        }
        if(mp.size()==cap){
            Node* lru = tail->prev; 
            mp.erase(lru->key);
            del(lru);
            delete lru;
        }
        Node* nd=new Node(key,value);
        add(nd);
        mp[key]=nd;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */