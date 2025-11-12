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


bool isBST(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main() {
    Node* a = new Node(4);
    a->left = new Node(2);
    a->right = new Node(6);
    a->left->left = new Node(1);
    a->left->right = new Node(3);
    a->right->left = new Node(5);
    a->right->right = new Node(7);

    if (isBST(a, INT_MIN, INT_MAX))
        cout << "This is a BST\n";
    else
        cout << "This is NOT a BST\n";

    return 0;
}