#include <iostream>
#include <string>
#include <memory>

int main()
{
	std::unique_ptr<std::string> p1(new std::string("hello"));
// 	std::unique_ptr<std::string> p2 = p1; 
// 12_16.cpp: In function 'int main()':
// 12_16.cpp:8:36: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]'
//     8 |  std::unique_ptr<std::string> p2 = p1;
//       |                                    ^~
// In file included from /usr/include/c++/9/memory:80,
//                  from 12_16.cpp:3:
// /usr/include/c++/9/bits/unique_ptr.h:414:7: note: declared here
//   414 |       unique_ptr(const unique_ptr&) = delete;
//       |       ^~~~~~~~~~

	std::cout << *p1 << std::endl;
	p1.reset(nullptr);
	return 0;
}