#ifndef TMAINWINDOW_H
#define TMAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
#include <QLayout>
#include <QCheckBox>

#include <vector>

class TQuestionsTest;

class TMainWindow : public QWidget {
	Q_OBJECT
	public:
	explicit TMainWindow(const TQuestionsTest* test, QWidget *parent = nullptr);

	signals:

	private:
	void BuildStartButton();
	void BuildQuestionLayout();

	private:
	void UpdateQuestionLayout();
	void SaveGivenAnswers();
	void LoadGivenAnswers();
	void FinishTest();

	private slots:
	void OnStartButton();
	void OnNextButton();
	void OnBackButton();
	void OnFinishButton();

	private:
	QPushButton* m_pStartButton = nullptr;

	QLabel* m_pQuestionNumber = nullptr;
	QLabel* m_pQuestionText = nullptr;
	QVBoxLayout* m_pAnswersLayout = nullptr;
	QWidget* m_pAnswersContents = nullptr;
	QScrollArea* m_pScrollArea = nullptr;
	QPushButton* m_pNextButton = nullptr;
	QPushButton* m_pBackButton = nullptr;
	QPushButton* m_pFinishButton = nullptr;
	QLabel* m_pTimeLabel = nullptr;
	QLabel* m_pTimeLeft = nullptr;

	QLabel* m_pResultsLabel = nullptr;

	private:
	QList<QCheckBox*> m_vAnswers;

	private:
	const TQuestionsTest* m_pTest;

	private:
	std::vector<std::vector<bool>> m_vGivenAnswers;
	unsigned m_uCurrentQuestionIndex = 0;
};

#endif // TMAINWINDOW_H
