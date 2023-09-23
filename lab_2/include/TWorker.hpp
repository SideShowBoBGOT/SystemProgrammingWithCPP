#ifndef LAB_1_TWORKER_H
#define LAB_1_TWORKER_H

#include <TUser.hpp>

class TAgeTooSmallException;

class TWorker : public TUser {
    public:
    TWorker()=default;
	virtual ~TWorker()=default;

    public:
	virtual auto Age(unsigned age) -> std::expected<std::monostate, TAgeTooSmallException> override;
 
	virtual unsigned PositionId() const;
    virtual void PositionId(unsigned positionId);

	public:
	friend std::ostream& operator<<(std::ostream& out, const TWorker& worker);
    
    protected:
	virtual std::ostream& Print(std::ostream& out) const override;

	protected:
    unsigned m_uPositionId = 0;
    
    private:
	friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar & boost::serialization::base_object<TUser>(*this);
        ar & m_uPositionId;
    }
};


#endif //LAB_1_TWORKER_H
