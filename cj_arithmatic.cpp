#include <iostream>
#include <string>

using namespace std;

void print(const string& input) {
    cout << "Arithmetic operators: ";
    for (char c : input) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            cout << c << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter an expression: ";
    cin >> input;

    print(input);

    return 0;
}
