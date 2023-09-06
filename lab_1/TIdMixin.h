#ifndef LAB_1_TIDMIXIN_H
#define LAB_1_TIDMIXIN_H

#include <type_traits>

class TIdMixin {
	public:
	TIdMixin()=default;
	virtual ~TIdMixin()=default;
	
	virtual unsigned Id() const;
    virtual void Id(unsigned id);
	
	protected:
	unsigned m_uId = 0;
};


#endif //LAB_1_TIDMIXIN_H
