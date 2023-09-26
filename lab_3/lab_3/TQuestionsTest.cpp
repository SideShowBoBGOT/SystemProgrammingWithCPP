#include "TQuestionsTest.h"

TQuestionsTest::TQuestionsTest(const std::optional<std::chrono::seconds>& seconds) : Seconds{seconds} {}

TQuestionsTest& TQuestionsTest::AddQuestion(const TQuestion& question) {
    Questions.emplace_back(question);
    return *this;
}
