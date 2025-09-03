#include <iostream>
#include <string>
using namespace std;

#define MAX 100  // max size for stack

struct Stack {
    char arr[MAX];
    int top;
};

Stack init() {
    Stack S;
    S.top = -1;
    return S;
}

bool isEmpty(Stack S) {
    return (S.top == -1);
}

bool isFull(Stack S) {
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

char pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.arr[S.top--];
    } else {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
}

char peek(Stack S) {
    if (!isEmpty(S)) {
        return S.arr[S.top];
    } else {
        return '\0'; // if empty
    }
}

// Function to check if brackets are balanced
bool isBalanced(string s) {
    Stack S = init();

    for (char c : s) {
        // If opening bracket → push
        if (c == '(' || c == '{' || c == '[') {
            S = push(S, c);
        }
        // If closing bracket → check match
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(S)) return false; // nothing to match

            char topChar = peek(S);
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false; // mismatch
            }
            pop(S); // matched, so remove
        }
    }

    return isEmpty(S); // if empty at end → balanced
}

int main() {
    string s = "[{()}]";
    if (isBalanced(s)) {
        cout << "The string is balanced." << endl;
    } else {
        cout << "The string is not balanced." << endl;
    }
    return 0;
}