#include <string>

using std::string;

typedef string str_arr[10];

str_arr &func(){};

auto func() -> string(&)[10] {};

string s[10];

decltype(s) &func() {};
