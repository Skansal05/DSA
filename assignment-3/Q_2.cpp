#include <iostream>
using namespace std;

#define MAX 100   // Maximum size of the stack (enough for string)

struct Stack {
    char arr[MAX];
    int top;
};

Stack init() {
    Stack S;
    S.top = -1;
    return S;
}

int isEmpty(Stack S) {
    return (S.top == -1);
}

int isFull(Stack S) {
    return (S.top == MAX - 1);
}

Stack push(Stack S, char c) {
    if (!isFull(S)) {
        S.arr[++S.top] = c;
    } else {
        cout << "Stack Overflow!" << endl;
    }
    return S;
}

char pop(Stack &S) {  // pass by reference since we modify stack
    if (!isEmpty(S)) {
        return S.arr[S.top--];
    } else {
        cout << "Stack Underflow!" << endl;
        return '\0';  // return null char
    }
}

string reverseString(string str) {
    Stack S = init();

    // Push all characters into stack
    for (char c : str) {
        S = push(S, c);
    }

    // Pop all characters to get reversed string
    string reversed = "";
    while (!isEmpty(S)) {
        reversed += pop(S);
    }

    return reversed;
}

int main() {
    string input = "DataStructure";
    cout << "Original: " << input << endl;
    cout << "Reversed: " << reverseString(input) << endl;
    return 0;
}
