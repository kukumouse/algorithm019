class LRUCache {
private:
    typedef list<int> LI;
    typedef pair<int,LI::iterator> PI;
    typedef unordered_map<int,PI> HIPI;
    LI used;
    HIPI cache;
    int _capacity;
    void update(HIPI::iterator it){
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        update(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()){
            update(it);
        }else{
            if (cache.size() == _capacity){
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value,used.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
