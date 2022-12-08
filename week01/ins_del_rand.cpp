mt19937 rnd(0);
class RandomizedSet {
public:
    vector<int> storage;
    unordered_map<int, int> link;
    //here, int->int = val(key)->storage_index(value)
    RandomizedSet() {
    }

    bool insert(int val) {
        if(link.count(val))
            return false;
        storage.push_back(val);
        link[val] = storage.size()-1;
        return 1;
    }

    bool remove(int val) {
        if(!link.count(val)) return false;

        //swap the would be remove index with last index
        int index_1=link[val];
        int index_2=storage.size()-1;

        swap(storage[index_1], storage[index_2]); // (last value, would be removed value)

        //last index of the storage will be updated in link
        link[storage[index_1]] = index_1;
        //remove the last indexed value from storage
        storage.pop_back();
        //remove the key from map
        link.erase(val);

        return true;
    }

    int getRandom() {
        //x % n -> [0, n-1]
        int rand_index = rnd()%(storage.size());
        return storage[rand_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
