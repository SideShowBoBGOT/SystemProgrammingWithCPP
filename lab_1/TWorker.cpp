#include "TWorker.h"

int TWorker::Id() const {
    return 0;
}

void TWorker::Id(int id) {

}

const std::string &TWorker::Name() const {
    return m_sName;
}

void TWorker::Name(const std::string &name) {

}

const std::string &TWorker::Patronym() const {
    return m_sPatronym;
}

void TWorker::Patronym(const std::string &name) {

}

const std::string &TWorker::Surname() const {
    return m_sSurname;
}

void TWorker::Surname(const std::string &name) {

}

EGender TWorker::Gender() const {
    return m_xGender;
}

void TWorker::Gender(EGender gender) {

}

const std::string &TWorker::Residence() const {
    return m_sResidence;
}

void TWorker::Residence(const std::string &name) {

}

int TWorker::Age() const {
    return m_iAge;
}

void TWorker::Age(int age) {

}

const std::string &TWorker::PassportData() const {
    return m_sPassportData;
}

void TWorker::PassportData(const std::string &name) {

}

int TWorker::PositionId() const {
    return 0;
}

void TWorker::PositionId(int age) {

}
