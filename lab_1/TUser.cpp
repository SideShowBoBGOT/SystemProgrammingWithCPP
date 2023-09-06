#include "TUser.h"

#include <variant>
#define FMT_HEADER_ONLY
#include <fmt/core.h>

unsigned int TUser::Id() const {
    return 0;
}

void TUser::Id(unsigned int id) {
	m_uId = id;
}

const std::string &TUser::Name() const {
    return m_sName;
}

void TUser::Name(const std::string &name) {
	m_sName = name;
}

const std::string &TUser::MiddleName() const {
    return m_sMiddleName;
}

void TUser::MiddleName(const std::string &middleName) {
	m_sMiddleName = middleName;
}

const std::string &TUser::Surname() const {
    return m_sSurname;
}

void TUser::Surname(const std::string &surname) {
	m_sSurname = surname;
}

EGender TUser::Gender() const {
    return m_xGender;
}

auto TUser::Gender(EGender gender) -> std::variant<std::monostate, std::invalid_argument> {
	if(gender==EGender::None) {
		return std::invalid_argument(
			fmt::format("Gender can not be none")
		);
	}
	m_xGender = gender;
	return std::monostate{};
}

const std::string &TUser::Residence() const {
    return m_sResidence;
}

void TUser::Residence(const std::string &residence) {
	m_sResidence = residence;
}

unsigned int TUser::Age() const {
    return m_uAge;
}

void TUser::Age(unsigned int age) {
	m_uAge = age;
}

const std::string &TUser::PassportData() const {
    return m_sPassportData;
}

void TUser::PassportData(const std::string &passportData) {
	m_sPassportData = passportData;
}