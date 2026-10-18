//struct is a class with public members by default
struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        //link to new trie
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            //moves to reference trie
            node=node->get(word[i]);
        }
        //standing at last
        node->setEnd();
    }
    
    bool search(string word) {
        //start at root node
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        //start at root
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])) return false;
            node=node->get(prefix[i]);
        }
        //if it exists till prefixes end then no need to check
        return true;
    }
};
