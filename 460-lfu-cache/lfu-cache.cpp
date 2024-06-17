class LFUCache {
public:
    int cachesize, recent = 0;
    unordered_map<int, int> freqaccess;
    unordered_map<int, int> keyvalue;
    set<pair<pair<int, int>, int>> cache;
    unordered_map<int, bool> existsincache;
    unordered_map<int, int> recentvalueto;

    LFUCache(int capacity) { cachesize = capacity; }

    int get(int key) {
        if (cachesize == 0) {
            return -1;
        }
        if (!existsincache[key]) {
            return -1;
        }
        cache.erase({{freqaccess[key], recentvalueto[key]}, key});
        freqaccess[key]++;
        recentvalueto[key] = recent;
        cache.insert({{freqaccess[key], recentvalueto[key]}, key});
        recent++;
        return keyvalue[key];
    }

    void put(int key, int value) {
        if (cachesize == 0) {
            return;
        }
        if (!existsincache[key]) {
            if (cache.size() == cachesize) {
                existsincache[(*cache.begin()).second] = false;
                cache.erase(cache.begin());
            }
            keyvalue[key] = value;
            freqaccess[key] = 1;
            recentvalueto[key] = recent;
            cache.insert({{freqaccess[key], recentvalueto[key]}, key});
            recent++;
            existsincache[key] = true;
        } else {
            keyvalue[key] = value;
            cache.erase({{freqaccess[key], recentvalueto[key]}, key});
            freqaccess[key]++;
            recentvalueto[key] = recent;
            cache.insert({{freqaccess[key], recentvalueto[key]}, key});
            recent++;
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */