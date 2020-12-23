#include <iostream>
#include <string>

using std::string; using std::cin; using std::cout; using std::endl;

int main() {
    string prev, curr;
    while (cin >> curr) {
        if (curr == prev) {
            break;
        }
        prev = curr;
    }
    if (cin.eof()) {
        cout << "no repeated" << endl;
    } else {
        cout << curr << endl;
    }
    return 0;
}