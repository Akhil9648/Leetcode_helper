struct Node {
    int key, value, count;
    Node* next, *prev;

    Node(int k, int v, int c) {
        key = k;
        value = v;
        count = c;
    }
};

class LFUCache {
public:
    int cap, cnt = 1;

    unordered_map<int, list<Node*>> cache;
    unordered_map<int, list<Node*>::iterator> mp;

    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.count(key)) {

            auto node = *mp[key];

            int value = node->value;
            int count = node->count;

            cache[count].erase(mp[key]);
            auto it = cache[count + 1].insert(
                cache[count + 1].end(), node
            );
            mp[key] = it;

            node->count++;
            if (cache[count].size() == 0 && cnt == count)
                cnt++;

            return value;
        }

        return -1;
    }

    void put(int key, int value) {

        if (mp.count(key)) {

            auto node = *mp[key];
            int count = node->count;

            cache[count].erase(mp[key]);
            auto it = cache[count + 1].insert(
                cache[count + 1].end(), node
            );
            mp[key] = it;

            node->count++;
            node->value = value;

            if (cache[count].size() == 0 && cnt == count)
                cnt++;

            return;
        }
        if (cap == 0)
            return;

        if (mp.size() == cap) {
            auto node = cache[cnt].front();
            cache[cnt].pop_front();
            mp.erase(node->key);
            delete node;
        }

        Node* curr = new Node(key, value, 1);
        auto it = cache[1].insert(
            cache[1].end(), curr
        );
        mp[key] = it;
        cnt = 1;
    }
};