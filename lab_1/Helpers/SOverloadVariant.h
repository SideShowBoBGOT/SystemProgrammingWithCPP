#ifndef LAB_1_SOVERLOADVARIANT_H
#define LAB_1_SOVERLOADVARIANT_H

template<class... Ts>
struct SOverloadVariant : Ts... { using Ts::operator()...; };

template<class... Ts>
SOverloadVariant(Ts...) -> SOverloadVariant<Ts...>;

#endif //LAB_1_SOVERLOADVARIANT_H
