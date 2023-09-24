#ifndef TMAINWINDOW_H
#define TMAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>

class TQuestionsTest;

class TMainWindow : public QWidget {
	Q_OBJECT
	public:
	explicit TMainWindow(const TQuestionsTest& test, QWidget *parent = nullptr);

	signals:

	private:
	void BuildStartButton();
	void BuildQuestionLayout();


	private slots:
	void OnStartButton();

	private:
	QPushButton* m_pStartButton = nullptr;

	QLabel* m_pQuestionNumber = nullptr;
	QLabel* m_pQuestionText = nullptr;
	QScrollArea* m_pAnswersArea = nullptr;
	QPushButton* m_pNextButton = nullptr;
	QPushButton* m_pBackButton = nullptr;

};

#endif // TMAINWINDOW_H
