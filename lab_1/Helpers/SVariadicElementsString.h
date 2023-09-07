#ifndef LAB_1_SVARIADICELEMENTSSTRING_H
#define LAB_1_SVARIADICELEMENTSSTRING_H

#include <string>

template<typename Id, typename ...Ids>
struct SVariadicElementsString {
	std::string operator()(Id id, Ids... ids) {
		return std::to_string(id) + ", " + SVariadicElementsString<Ids...>()(ids...);
	}
};

template<typename Id>
struct SVariadicElementsString<Id> {
	std::string operator()(Id id) {
		return std::to_string(id);
	}
};

#endif //LAB_1_SVARIADICELEMENTSSTRING_H
