#ifndef LAB_1_NNHELPERFUNCS_H
#define LAB_1_NNHELPERFUNCS_H

#include <magic_enum.hpp>

#include <type_traits>
#include <string>
#include <map>
#include <sstream>

namespace NNHelperFuncs {
	template<typename EnumType> requires std::is_enum_v<EnumType>
	std::map<std::string, EnumType> EnumMapStringValue() {
		auto m = std::map<std::string, EnumType>();
		for(auto el : magic_enum::enum_values<EnumType>()) {
			m.emplace(magic_enum::enum_name<EnumType>(el), el);
		}
		return m;
	}
	
	std::string TitledString(const std::string& str);
	
	template<typename T>
	std::string VectorString(const std::vector<T>& vv, const std::string& sep = ", ") {
		if(vv.empty()) {
			return "";
		}
		
		std::stringstream ss;
		
		for(auto i = 0u; i < vv.size() - 1; ++i) {
			ss << vv[i] << sep;
		}
		ss << vv[vv.size() - 1];
		
		return ss.str();
	}
};

#endif //LAB_1_NNHELPERFUNCS_H
