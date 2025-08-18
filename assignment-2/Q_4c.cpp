#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string result = "";  // empty string to build output

    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;  // append non-vowel characters
        }
    }

    cout << "String without vowels: " << result << endl;

    return 0;
}