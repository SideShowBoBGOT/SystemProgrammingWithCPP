#ifndef LAB_3_TQUESTIONSTEST_H
#define LAB_3_TQUESTIONSTEST_H

#include "TQuestion.h"

#include <chrono>
#include <optional>

class TQuestionsTest {
	public:
	explicit TQuestionsTest(const std::optional<std::chrono::seconds>& seconds);
    TQuestionsTest& AddQuestion(const TQuestion& question);

	std::optional<std::chrono::seconds> Seconds;
    std::vector<TQuestion> Questions;
};

#endif //LAB_3_TQUESTIONSTEST_H
