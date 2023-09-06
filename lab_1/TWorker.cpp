#include "TWorker.h"

#include <format>

static constexpr double s_dMinWorkerAge = 18.0;

unsigned int TWorker::PositionId() const {
    return m_uPositionId;
}

void TWorker::PositionId(unsigned positionId) {
	m_uPositionId = positionId;
}

auto TWorker::Age(unsigned age) -> std::expected<void, std::invalid_argument> {
	if(age <= s_dMinWorkerAge) {
		return std::unexpected(
			std::invalid_argument(
				std::format(R"(Age of worker "{}" is less than minimal age "{}")", age, s_dMinWorkerAge)
			)
		);
	}
	return TUser::Age(age);
}
