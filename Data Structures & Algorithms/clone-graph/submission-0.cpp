/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void clone(unordered_map<Node*,Node*> &hash, Node* node){
        if(hash.count(node)) return;
        hash[node]=new Node(node->val);
        for(auto i: node->neighbors){
            clone(hash,i);
            hash[node]->neighbors.push_back(hash[i]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> hash;
        clone(hash,node);
        return hash[node];
    }
};
