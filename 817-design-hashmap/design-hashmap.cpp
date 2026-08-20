class MyHashMap {
public:
    vector<vector<pair<int,int>>>arr;
    int sz=1e4;
    MyHashMap() {
        arr.resize(sz);
    }
    
    void put(int key, int value) {
        int hash=key%sz;
        for(auto &it:arr[hash]){
            if(it.first==key){
                it.second=value;
                return;
            }
        }
        arr[hash].push_back({key,value});
    }
    
    int get(int key) {
        int hash=key%sz;
        for(auto &it:arr[hash]){
            if(it.first==key) return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash=key%sz;
        for(auto &it:arr[hash]){
            if(it.first==key){
                it.second=-1;
                break;
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */