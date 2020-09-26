#include <iostream>

int main() {
    int v1, v2;
    std::cin >> v1 >> v2;
    if (v1 > v2) {
        std::swap(v1, v2);
    }
    while (v1 <= v2) {
        std::cout << v1++ << " ";
    }
    std::cout << std::endl;
    return 0;
}

// 1_12
// -100加到100, 0

// 1_14
// 循环次数是否确定