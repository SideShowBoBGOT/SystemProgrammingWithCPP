#ifndef LAB_1_TWORKER_H
#define LAB_1_TWORKER_H

#include <iostream>
#include "EGender.h"

class TWorker {

    public:
    TWorker()=default;

    public:
    int Id() const;
    void Id(int id);

    const std::string& Name() const;
    void Name(const std::string& name);

    const std::string& Patronym() const;
    void Patronym(const std::string& name);

    const std::string& Surname() const;
    void Surname(const std::string& name);

    EGender Gender() const;
    void Gender(EGender gender);

    const std::string& Residence() const;
    void Residence(const std::string& name);

    int Age() const;
    void Age(int age);

    const std::string& PassportData() const;
    void PassportData(const std::string& name);

    int PositionId() const;
    void PositionId(int age);


    protected:
    int m_iId = -1;

    std::string m_sName;
    std::string m_sPatronym;
    std::string m_sSurname;

    EGender m_xGender = EGender::None;

    std::string m_sResidence;

    int m_iAge = -1;

    std::string m_sPassportData;

    int m_iPositionId = -1;
};


#endif //LAB_1_TWORKER_H
