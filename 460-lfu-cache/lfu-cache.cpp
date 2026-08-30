struct Node{
    int key,value,count;
    Node(int k,int v,int c){
        key=k;
        value=v;
        count=c;
    }
};
class LFUCache {
public:
    int cap,count=1;
    unordered_map<int, list<int>> cache; 
    unordered_map<int, Node*> mp;
    unordered_map<int, list<int>::iterator> pos;
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* curr=mp[key];
            int lvl=curr->count;
            cache[lvl].erase(pos[key]);
            cache[lvl+1].push_back(key);
            pos[key] = --cache[lvl+1].end(); 
            curr->count++;
            if(cache[count].size()==0 && lvl == count) count++;
            return curr->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if(mp.count(key)){
            Node* curr=mp[key];
            int lvl=curr->count;
            cache[lvl].erase(pos[key]);
            cache[lvl+1].push_back(key);
            pos[key] = --cache[lvl+1].end(); 
            if(cache[count].size()==0 && lvl == count) count++;
            curr->count++;
            curr->value=value;
            return;
        }
        if(mp.size()==cap){
            int curr_key = cache[count].front();
            cache[count].pop_front();
            mp.erase(curr_key);
            pos.erase(curr_key);

        }
        cache[1].push_back(key);
        pos[key] = --cache[1].end(); 
        Node* curr=new Node(key,value,1);
        count=1;
        mp[key]=curr;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */