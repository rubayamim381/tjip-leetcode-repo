class LRUCache {
public:

    list<int> LRU; //for list the key value
    map<int, int> key_value; //for put and get operation
    map<int, list<int>::iterator> addr_mp; //for connecting it's address with LRU
    int max_capacity;

    LRUCache(int capacity) {
        max_capacity = capacity;
    }

    int get(int key) {

        if(key_value.count(key) == 0)
            return -1;

        updateLRU(key);
        return key_value[key];

    }

    void put(int key, int value) {
        //Task 1: New key is inserting from first
        //Task 2: IF the new key has already existed in the list, update the new value of the key and drag it to the first
        //Task 3: IF the list is full and the new to-be inserted key is not present in the list, delete the least recent used, actually last key from list, place the new key there and drag it to the first position in the list

        if(key_value.size() == max_capacity && key_value.count(key) == 0)
            evict();

        updateLRU(key);
        key_value[key] = value;
        return;
    }

    void updateLRU(int key)
    {
        if(key_value.count(key))
            LRU.erase(addr_mp[key]);
        LRU.push_front(key);
        addr_mp[key] = LRU.begin();
    }

    void evict(){
        int last_key = LRU.back();
        addr_mp.erase(last_key);
        key_value.erase(last_key);
        LRU.pop_back();
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
