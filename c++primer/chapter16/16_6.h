template <typename T, unsigned N>
T* begin(const T (&arr)[N]) {
    return arr;
}

template <typename T, unsigned N>
T* end(const T (&arr)[N]) {
    return arr + N;
}