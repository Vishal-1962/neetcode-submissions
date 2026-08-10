class LRUCache {
public:
    int capacity;

    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        // Get iterator
        auto it = mp[key];

        int value = it->second;

        // Move this item to front
        cache.erase(it);
        cache.push_front({key, value});

        // Update map
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            cache.erase(mp[key]);
        }

        // Add to front
        cache.push_front({key, value});

        // Update map
        mp[key] = cache.begin();

        // Capacity exceeded
        if (cache.size() > capacity) {

            auto last = cache.back();

            mp.erase(last.first);

            cache.pop_back();
        }
    }
};