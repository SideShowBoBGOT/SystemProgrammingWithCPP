#ifndef LAB_1_TIDMIXIN_H
#define LAB_1_TIDMIXIN_H

#include <type_traits>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class TIdMixin {
	public:
	TIdMixin()=default;
	virtual ~TIdMixin()=default;
	
	virtual unsigned Id() const;
    virtual void Id(unsigned id);
	
	public:
	friend std::ostream& operator<<(std::ostream& out, const TIdMixin& id);
	
	protected:
	virtual std::ostream& Print(std::ostream& out) const;
	
	protected:
	unsigned m_uId = 0;
	
	private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar & m_uId;
	}
};


#endif //LAB_1_TIDMIXIN_H
