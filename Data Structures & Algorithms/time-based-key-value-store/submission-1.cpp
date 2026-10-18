class TimeMap {
unordered_map<string,vector<string>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        //resize vector to settle key
        if(mp[key].size()<=timestamp){
            mp[key].resize(timestamp+1);
        }
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        //checking is key is present or not
        if (mp.find(key) == mp.end()) return "";

        if(timestamp>=mp[key].size()) timestamp=mp[key].size()-1;
        for(int i=timestamp;i>=0;i--){
            if(!mp[key][i].empty()) return mp[key][i];
        }
        return "";
    }
};
