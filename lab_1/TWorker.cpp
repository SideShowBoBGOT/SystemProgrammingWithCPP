#include "TWorker.h"

#define FMT_HEADER_ONLY
#include <fmt/core.h>

static constexpr double s_dMinWorkerAge = 18.0;

unsigned int TWorker::PositionId() const {
    return m_uPositionId;
}

void TWorker::PositionId(unsigned positionId) {
	m_uPositionId = positionId;
}

void TWorker::Age(unsigned age) {
	if(age <= s_dMinWorkerAge) {
		throw std::invalid_argument(
			fmt::format(R"(Age of worker "{}" is less than minimal age "{}")", age, s_dMinWorkerAge)
		);
	}
	TUser::Age(age);
}
