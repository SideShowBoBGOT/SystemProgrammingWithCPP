#ifndef LAB_3_TQUESTION_H
#define LAB_3_TQUESTION_H

#include <string>
#include <vector>

struct SAnswer {
    std::string Text;
    bool IsCorrect = false;
};

class TQuestion {
    public:
    explicit TQuestion(const std::string& text, unsigned points);
    TQuestion& AddAnswer(const SAnswer& answer);

    unsigned Points = 0;
    std::string Text;
    std::vector<SAnswer> Answers;
};


#endif //LAB_3_TQUESTION_H
