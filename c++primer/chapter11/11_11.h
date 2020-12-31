#include <set>

using namespace std;
class Sales_data;

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs);

multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);
