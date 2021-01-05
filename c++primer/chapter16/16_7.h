template <typename T, unsigned N> constexpr
unsigned size(const T (&arr)[N]) {
    return N;
}