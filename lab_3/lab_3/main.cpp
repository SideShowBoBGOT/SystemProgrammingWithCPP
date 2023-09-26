#include "TQuestionsTest.h"
#include "TMainWindow.h"

#include <QApplication>

TQuestionsTest BuildQuestionTest();

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	const auto test = BuildQuestionTest();
	auto w = TMainWindow(&test);
	w.show();
    return a.exec();
}

TQuestionsTest BuildQuestionTest() {
	using namespace std::chrono_literals;

	return TQuestionsTest(10s)
		.AddQuestion(
			TQuestion("Who created C language?", 1)
				.AddAnswer({"Dennis Ritchie", true})
				.AddAnswer({"Ken Thompson", true})
				.AddAnswer({"Bjarne Stroustrup", false})
		)
		.AddQuestion(
			TQuestion("Does Java use garbage collector?", 1)
				.AddAnswer({"Yes", true})
				.AddAnswer({"No", false})
		)
		.AddQuestion(
			TQuestion("Does C++ use garbage collector?", 5)
				.AddAnswer({"Yes", false})
				.AddAnswer({"No", true})
		)
		.AddQuestion(
			TQuestion("Under what license is GNU C++ Compiler distributed?", 2)
				.AddAnswer({"MIT", false})
				.AddAnswer({"GPL 2", false})
				.AddAnswer({"GPL 3", true})
				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//			.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
//				.AddAnswer({"Apache", false})
		);
}
