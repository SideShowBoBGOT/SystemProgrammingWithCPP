#ifndef LAB_1_TUSER_H
#define LAB_1_TUSER_H

#include <iostream>
#include <memory>
#include <expected>
#include <variant>

#include "EGender.h"
#include "TIdMixin.h"

class TAgeTooSmallException;

class TUser : public TIdMixin {
	public:
	TUser()=default;
	virtual ~TUser()=default;
	
	public:
    virtual const std::string& Name() const;
    virtual void Name(const std::string& name);

    virtual const std::string& MiddleName() const;
    virtual void MiddleName(const std::string& middleName);

    virtual const std::string& Surname() const;
    virtual void Surname(const std::string& surname);

    virtual EGender Gender() const;
    virtual void Gender(EGender gender);

    virtual const std::string& Residence() const;
    virtual void Residence(const std::string& residence);

    virtual unsigned Age() const;
    virtual auto Age(unsigned age) -> std::expected<std::monostate, TAgeTooSmallException>;

    virtual const std::string& PassportData() const;
    virtual void PassportData(const std::string& passportData);
    
    public:
	friend std::ostream& operator<<(std::ostream& out, const TUser& user);
    
    protected:
	virtual std::ostream& Print(std::ostream& out) const override;
    
    protected:
    std::string m_sName;
    std::string m_sMiddleName;
    std::string m_sSurname;

    EGender m_xGender = EGender::Male;

    std::string m_sResidence;

    unsigned m_uAge = 0;

    std::string m_sPassportData;
	
	private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
        ar & boost::serialization::base_object<TIdMixin>(*this);
        ar & m_sName;
        ar & m_sMiddleName;
        ar & m_sSurname;
        ar & m_xGender;
        ar & m_sResidence;
        ar & m_uAge;
        ar & m_sPassportData;
    }
};


#endif //LAB_1_TUSER_H
