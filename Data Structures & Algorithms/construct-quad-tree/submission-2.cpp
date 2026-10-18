/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* solve(vector<vector<int>>& grid,int n, int r, int c){
        bool allsame=true;
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        if(grid[r+i][c+j] != grid[r][c]) {
            allsame = false;
            break;
        }
    }
    if(!allsame) break;
}

        if(allsame) return new Node(grid[r][c]==1,true);
        int mid=n/2;
        Node* topLeft=solve(grid,mid,r,c);
        Node* topRight=solve(grid,mid,r,c+mid);
        Node* bottomLeft=solve(grid,mid,r+mid,c);
        Node* bottomRight=solve(grid,mid,r+mid,c+mid);
        return new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);

    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,grid.size(),0,0);
    }
};