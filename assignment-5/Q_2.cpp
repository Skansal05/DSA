#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int countAndDelete(Node*& head, int key) {
    int count = 0;

    while (head && head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        count++;
    }

    Node* current = head;
    while (current && current->next) {
        if (current->next->data == key) {
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
            count++;
        } else {
            current = current->next;
        }
    }
    return count;
}

void displayList(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int val : arr)
        insertAtEnd(head, val);

    cout << "Original Linked List: ";
    displayList(head);

    int key = 1;
    int count = countAndDelete(head, key);

    cout << "Count of " << key << ": " << count << endl;
    cout << "Updated Linked List: ";
    displayList(head);

    return 0;
}