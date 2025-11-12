#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int value){ 
        data = value;
        right = left = nullptr;
    }
};

Node* insertIntoBST(Node* root, int val) {
    if(!root) return new Node(val);
    else if(root->data>val) root->left=insertIntoBST(root->left,val);
    else root->right=insertIntoBST(root->right,val);
    return root;    
}

Node* inorder_pred(Node* root){
    Node* pred = root->left;
    while(pred->right){
         pred = pred->right;
    }   
    return pred;
}
Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;
    if (root->data == key){
    if(!root->left && !root->right) return NULL; 

    else if(!root->left || !root->right){
        if(root->left) return root->left;
        else return root->right;
    }
        Node* pred = inorder_pred(root);
        root->data = pred->data;
        root->left = deleteNode(root->left, pred->data);
    }
       
    else if (root->data > key) {
        root->left = deleteNode(root->left, key);
    }
    else {
        root->right = deleteNode(root->right, key);
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main(){
    Node* a = new Node(4); // root
    Node* b = new Node(2);
    Node* c = new Node(6);
    Node* d = new Node(1);
    Node* e = new Node(3);
    Node* f = new Node(5);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    cout<<maxDepth(a)<<endl;
    cout<<minDepth(a)<<endl;
    return 0;
}