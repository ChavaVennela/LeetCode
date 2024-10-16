/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>>a;
        if(root != NULL){
            a.push({root, 0});
        }
        while(!a.empty()){
            pair<Node*, int>temp=a.front();
            a.pop();
            if(temp.first->left != NULL){
                a.push({temp.first->left, temp.second+1});
            }
            if(temp.first->right != NULL){
                a.push({temp.first->right, temp.second+1});
            }
            if(!a.empty() && a.front().second==temp.second){
                temp.first->next=a.front().first;
            }
        }
        return root;
    }
};