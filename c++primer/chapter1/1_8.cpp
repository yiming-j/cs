#include <iostream>

int main() {
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */"; //加一个引号
    std::cout << /* "*/" /* "/*" */;
}