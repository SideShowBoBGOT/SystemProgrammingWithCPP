#ifndef LAB_1_SSTRINGLITERAL_H
#define LAB_1_SSTRINGLITERAL_H

#include <iostream>
#include <algorithm>

template<unsigned N>
class SStringLiteral {
    constexpr SStringLiteral(const char (&str)[N]) {
        std::copy_n(str, N, Value);
    }
    char Value[N];
};

#endif //LAB_1_SSTRINGLITERAL_H
