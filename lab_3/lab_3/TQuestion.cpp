#include "TQuestion.h"

TQuestion::TQuestion(const std::string& text, unsigned points)
    : Text{text}, Points{points} {}

TQuestion& TQuestion::AddAnswer(const SAnswer& answer) {
    Answers.emplace_back(answer);
    return *this;
}
