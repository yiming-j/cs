#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string; using std::vector; using std::cout; using std::endl;
using std::partition;

bool isShorter(const string &str) {
    return str.size() >= 5;
}

int main() {
    vector<string> vec{"a", "aaa", "aaaa", "aaaaaaa", "aaaaa"};
    auto pos = partition(vec.begin(), vec.end(), isShorter);

    for (auto it = vec.cbegin(); it != pos; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}