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
	
	protected:
	std::string m_sTitle;
};


#endif //LAB_1_TBOOK_H
