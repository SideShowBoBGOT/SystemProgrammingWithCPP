#ifndef LAB_1_NNHELPERFUNCS_H
#define LAB_1_NNHELPERFUNCS_H

#include <type_traits>
#include <string>
#include <map>

#include <magic_enum.hpp>

namespace NNHelperFuncs {
	template<typename EnumType> requires std::is_enum_v<EnumType>
	std::map<std::string, EnumType> EnumMapStringValue() {
		auto m = std::map<std::string, EnumType>();
		for(auto el : magic_enum::enum_values<EnumType>()) {
			m.emplace(magic_enum::enum_name<EnumType>(el), el);
		}
		return m;
	}
};

#endif //LAB_1_NNHELPERFUNCS_H
