
class AllOne {
public:
    unordered_map<string, int> freq;
    set<pair<int, string>> s;
    AllOne() {}

    void inc(string key) {
        auto& count = freq[key];
        if (count) {
            s.erase({count, key});
        }
        count++;
        s.insert({count, key});
    }

    void dec(string key) {
        auto& count = freq[key];
        s.erase({count, key});
        count--;
        if (count) {
            s.insert({count, key});
        }
    }

    string getMaxKey() { return s.size() ? (s.rbegin())->second : ""; }

    string getMinKey() { return s.size() ? (s.begin())->second : ""; }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */