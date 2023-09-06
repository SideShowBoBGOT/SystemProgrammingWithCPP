#ifndef LAB_1_TUSER_H
#define LAB_1_TUSER_H

#include <iostream>
#include <memory>
#include <expected>

#include "EGender.h"

class TUser {
	public:
	TUser()=default;
	virtual ~TUser()=default;
	
	public:
	virtual unsigned Id() const;
    virtual void Id(unsigned id);

    virtual const std::string& Name() const;
    virtual void Name(const std::string& name);

    virtual const std::string& MiddleName() const;
    virtual void MiddleName(const std::string& middleName);

    virtual const std::string& Surname() const;
    virtual void Surname(const std::string& surname);

    virtual EGender Gender() const;
    virtual auto Gender(EGender gender) -> std::expected<void, std::invalid_argument>;

    virtual const std::string& Residence() const;
    virtual void Residence(const std::string& residence);

    virtual unsigned Age() const;
    virtual auto Age(unsigned age) -> std::expected<void, std::invalid_argument>;

    virtual const std::string& PassportData() const;
    virtual void PassportData(const std::string& passportData);
    
    protected:
    unsigned m_uId = 0;

    std::string m_sName;
    std::string m_sMiddleName;
    std::string m_sSurname;

    EGender m_xGender = EGender::None;

    std::string m_sResidence;

    unsigned m_uAge = 0;

    std::string m_sPassportData;
};


#endif //LAB_1_TUSER_H
