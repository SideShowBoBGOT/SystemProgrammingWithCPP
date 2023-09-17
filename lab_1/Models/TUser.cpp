#include "TUser.h"
#include "../Error/TAgeTooSmallException.h"
#include <magic_enum.hpp>

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

void TUser::Gender(EGender gender) {
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

auto TUser::Age(unsigned age) -> std::expected<std::monostate, TAgeTooSmallException> {
	m_uAge = age;
	return std::monostate();
}

const std::string &TUser::PassportData() const {
    return m_sPassportData;
}

void TUser::PassportData(const std::string &passportData) {
	m_sPassportData = passportData;
}

std::ostream& operator<<(std::ostream& out, const TUser& user) {
	return user.Print(out);
}

std::ostream& TUser::Print(std::ostream& out) const {
	auto& mout = TIdMixin::Print(out);
	#define AA(xx) mout << "\t"#xx": " << xx() << ", ";
		AA(Name);
		AA(MiddleName);
		AA(Surname);
		mout << "\tGender: " << magic_enum::enum_name(Gender()) << ", ";
		AA(Residence);
		AA(Age);
		AA(PassportData)
	#undef AA
	return mout;
}
