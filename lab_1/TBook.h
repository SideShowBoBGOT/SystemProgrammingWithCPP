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
	
	virtual const std::string& Author() const;
	virtual void Author(const std::string& author);
	
	protected:
	std::string m_sTitle;
	std::string m_sAuthor;
};


#endif //LAB_1_TBOOK_H
