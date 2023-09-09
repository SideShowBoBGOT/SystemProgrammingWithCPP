#ifndef LAB_1_TBOOK_H
#define LAB_1_TBOOK_H

#include <iostream>

#include "TIdMixin.h"

class TBook : public TIdMixin {
	public:
	TBook()=default;
	virtual ~TBook()=default;
	
	public:
	virtual const std::string& Title() const;
	virtual void Title(const std::string& title);
	
	public:
	friend std::ostream& operator<<(std::ostream& out, const TBook& book);
    
    protected:
	virtual std::ostream& Print(std::ostream& out) const override;
	
	protected:
	std::string m_sTitle;
	
	private:
	friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & boost::serialization::base_object<TIdMixin>(*this);
        ar & m_sTitle;
    }
};


#endif //LAB_1_TBOOK_H
