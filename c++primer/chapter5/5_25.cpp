#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

int main() {
    int num1, num2;
    cout << "please input two numbers: " << endl;
    while (cin >> num1 >> num2) {
        try {
            if (num2 == 0) {
                throw runtime_error("Error: divisor is 0");
            }
            cout << num1 / num2 << endl;
            return 0;
        } catch (runtime_error err) {
            cout << err.what() 
                << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n') {
                break;
            }
        }
        cout << "please input two numbers: " << endl;
    }
}

// Floating point exception