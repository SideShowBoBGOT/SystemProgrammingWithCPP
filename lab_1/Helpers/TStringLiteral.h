#ifndef LAB_1_TSTRINGLITERAL_H
#define LAB_1_TSTRINGLITERAL_H

#include <iostream>
#include <algorithm>

template<unsigned N>
class TStringLiteral {
	public:
    constexpr TStringLiteral(const char (&str)[N]) {
        std::copy_n(str, N, Value);
    }
    
	public:
    char Value[N];
};

#endif //LAB_1_TSTRINGLITERAL_H
