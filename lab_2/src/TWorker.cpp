#include "../include/TWorker.h"
#include "../include/TAgeTooSmallException.h"

#include <format>

static constexpr double s_dMinWorkerAge = 18.0;

unsigned int TWorker::PositionId() const {
    return m_uPositionId;
}

void TWorker::PositionId(unsigned positionId) {
	m_uPositionId = positionId;
}

auto TWorker::Age(unsigned age) -> std::expected<std::monostate, TAgeTooSmallException> {
	if(age <= s_dMinWorkerAge) {
		return std::unexpected(TAgeTooSmallException(age, s_dMinWorkerAge));
	}
	return TUser::Age(age);
}

std::ostream& operator<<(std::ostream& out, const TWorker& worker) {
	return worker.Print(out);
}

std::ostream& TWorker::Print(std::ostream& out) const {
	auto& mout = TUser::Print(out);
	#define AA(xx) mout << "\t"#xx": " << xx() << ", ";
		AA(PositionId)
	#undef AA
	return mout;
}