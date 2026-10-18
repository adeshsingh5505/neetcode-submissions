class MyHashMap {
private:
    unordered_map<int,int> hash;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        hash[key]=value;
        return;
    }
    
    int get(int key) {
        //if(key==0 && hash[0]==0) return 0;
        if(hash.find(key)==hash.end()) return -1;
        return hash[key];
    }
    
    void remove(int key) {
        hash.erase(key);
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