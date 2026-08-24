class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        const auto& vec = mp[key];
        auto it = std::upper_bound(vec.begin(), vec.end(), std::make_pair(timestamp, std::string("")), 
            [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
                return a.first < b.first;
            });
        if (it == vec.begin()) {
            return "";
        }
        return std::prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */