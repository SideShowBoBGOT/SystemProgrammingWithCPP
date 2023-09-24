#ifndef LAB_3_TQUESTIONSTEST_H
#define LAB_3_TQUESTIONSTEST_H

#include "TQuestion.h"
#include <chrono>

class TQuestionsTest {
    public:
    explicit TQuestionsTest(const std::chrono::seconds& seconds);
    TQuestionsTest& AddQuestion(const TQuestion& question);

    std::chrono::seconds Seconds{};
    std::vector<TQuestion> Questions;
};


//using namespace std::chrono_literals;
//const auto test = TQuestionsTest(30s)
//    .AddQuestion(
//        TQuestion("Who created C language?", 1)
//            .AddAnswer({"Dennis Ritchie", true})
//            .AddAnswer({"Ken Thompson", true})
//            .AddAnswer({"Bjarne Stroustrup", false})
//    )
//    .AddQuestion(
//        TQuestion("Does Java uses garbage collector?", 1)
//            .AddAnswer({"Yes", true})
//            .AddAnswer({"No", false})
//    )
//    .AddQuestion(
//        TQuestion("Under what license is GNU C++ Compiler distributed?", 2)
//            .AddAnswer({"MIT", false})
//            .AddAnswer({"GPL 2", false})
//            .AddAnswer({"GPL 3", true})
//            .AddAnswer({"Apache", false})
//    );
#endif //LAB_3_TQUESTIONSTEST_H
