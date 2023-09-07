#ifndef LAB_1_TWORKER_H
#define LAB_1_TWORKER_H

#include "TUser.h"

class TAgeTooSmallException;

class TWorker : public TUser {
    public:
    TWorker()=default;
	virtual ~TWorker()=default;

    public:
	virtual auto Age(unsigned age) -> std::expected<void, TAgeTooSmallException> override;
 
	virtual unsigned PositionId() const;
    virtual void PositionId(unsigned positionId);

	protected:
    unsigned m_uPositionId = 0;
};


#endif //LAB_1_TWORKER_H
