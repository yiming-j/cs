template<typename Container>
void print(const Container& c)
{
	for (typename Container::size_type i = 0; i != c.size(); ++i)
		std::cout << c[i] << " ";
}