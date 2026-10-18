class MyHashSet {
private:
    unordered_map<int,int> hash;
public:
    MyHashSet() {
    }
    
    void add(int key) {
        hash[key]++;
        return;
    }
    
    void remove(int key) {
        hash.erase(key);
        return;
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */