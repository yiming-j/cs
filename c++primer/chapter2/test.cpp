#include <iostream>

int main() {
    int i = 1;
    int &r = i;
    int *p = &r;
    std::cout << &i << " " << &r << " " << p << std::endl;

}