#include <iostream>
#include <vector>
// #include <initializer_list>

struct X
{
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
	~X() { std::cout << "~X()" << std::endl; }
};

void f(const X &rx, X x)
{
    std::cout << "f2" << std::endl;
	std::vector<X> vec;
	vec.reserve(2);
	vec.push_back(rx);
	vec.push_back(x);
    std::cout << "f3" << std::endl;
}

int main()
{
	X *px = new X;
    std::cout << "f1" << std::endl;
	f(*px, *px);
    std::cout << "f4" << std::endl;
	delete px;

	return 0;
}