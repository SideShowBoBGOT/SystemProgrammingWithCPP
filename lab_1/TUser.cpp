#include "TUser.h"

#include <format>

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

auto TUser::Gender(EGender gender) -> std::expected<void, std::invalid_argument> {
	if(gender==EGender::None) {
		return std::unexpected(std::invalid_argument("Gender can not be none"));
	}
	m_xGender = gender;
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

auto TUser::Age(unsigned int age) -> std::expected<void, std::invalid_argument> {
	m_uAge = age;
}

const std::string &TUser::PassportData() const {
    return m_sPassportData;
}

void TUser::PassportData(const std::string &passportData) {
	m_sPassportData = passportData;
}