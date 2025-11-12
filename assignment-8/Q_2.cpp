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

// Recursive Search
bool search(Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Iterative Search
bool searchIterative(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int findMax(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty";
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty";
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int inorder_pred(Node* root){
    if(!root || !root->left) return 0;
    Node* temp = root->left;
    while(temp->right){
        temp = temp->right;
    }
    return temp->data;
}

int inorder_succ(Node* root){
    if(!root || !root->right) return 0;
    Node* temp = root->right;
    while(temp->left){
        temp = temp->left;
    }
    return temp->data;
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


    cout<<search(a,5)<<endl;
    cout<<searchIterative(a,5)<<endl;
    cout<<findMax(a)<<endl;
    cout<<findMin(a)<<endl;
    cout<<findMax(a)<<endl;
    cout<<inorder_pred(b)<<endl;
    cout<<inorder_succ(b)<<endl;
    return 0;
}