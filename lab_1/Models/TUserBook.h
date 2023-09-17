#ifndef LAB_1_TUSERBOOK_H
#define LAB_1_TUSERBOOK_H

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class TUserBook {
	public:
	TUserBook()=default;
	explicit TUserBook(unsigned userId, unsigned bookId);
	virtual ~TUserBook()=default;
	
	bool operator==(const TUserBook& other) const;
	
	public:
	virtual unsigned UserId() const;
	virtual void UserId(unsigned userId);
	
	virtual unsigned BookId() const;
	virtual void BookId(unsigned bookId);
	
	public:
	friend std::ostream& operator<<(std::ostream& out, const TUserBook& userBook);
    
    protected:
	virtual std::ostream& Print(std::ostream& out) const;
	
	protected:
	unsigned m_uUserId = 0;
	unsigned m_uBookId = 0;
	
	private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar & m_uUserId;
		ar & m_uBookId;
	}
};


#endif //LAB_1_TUSERBOOK_H
