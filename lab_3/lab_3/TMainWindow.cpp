#include "TMainWindow.h"
#include "TQuestionsTest.h"



static constexpr int s_iWidth = 600;
static constexpr int s_iHeight = 600;

static constexpr int s_iStartButtonWidth = 100;
static constexpr int s_iStartButtonHeight = 100;
static const QString s_sStartButtonText = "Start";

static const QString s_sNextButtonText = "Next";
static const QString s_sBackButtonText = "Back";
static const QString s_sTimeLabelText = "Time left:";

TMainWindow::TMainWindow(const TQuestionsTest* test, QWidget *parent)
	: QWidget{parent}, m_pTest{test} {

	resize(s_iWidth, s_iHeight);

	BuildStartButton();
	BuildQuestionLayout();

	m_vGivenAnswers.resize(test->Questions.size());
	for(auto i = 0; i < test->Questions.size(); ++i) {
		m_vGivenAnswers[i].resize(test->Questions[i].Answers.size());
	}

}



void TMainWindow::BuildStartButton() {
	m_pStartButton = new QPushButton(this);

	m_pStartButton->setFixedWidth(width());
	m_pStartButton->setFixedHeight(height());
	m_pStartButton->setText(s_sStartButtonText);

	QObject::connect(m_pStartButton, &QPushButton::clicked, this, &TMainWindow::OnStartButton);

	m_pStartButton->hide();
}

void TMainWindow::BuildQuestionLayout() {
	auto layout = new QVBoxLayout(this);
	layout->setGeometry(QRect(0, 0, width(), height()));

	// QuestionNumber
	m_pQuestionNumber = new QLabel(this);
	m_pQuestionNumber->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
	layout->addWidget(m_pQuestionNumber);

	// QuestionText
	m_pQuestionText = new QLabel(this);
	m_pQuestionText->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
	layout->addWidget(m_pQuestionText);

	// AnswersArea
	m_pAnswersLayout = new QVBoxLayout(this);
	m_pAnswersContents = new QWidget(this);
	auto answersArea = new QScrollArea(this);

	answersArea->setWidgetResizable(true);
	answersArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
	answersArea->setWidget(m_pAnswersContents);

	layout->addWidget(answersArea);

	auto bottomLayout = new QHBoxLayout(this);

	m_pNextButton = new QPushButton(this);
	m_pNextButton->setText(s_sNextButtonText);
	QObject::connect(m_pNextButton, &QPushButton::clicked, this, &TMainWindow::OnNextButton);

	m_pBackButton = new QPushButton(this);
	m_pBackButton->setText(s_sBackButtonText);
	QObject::connect(m_pBackButton, &QPushButton::clicked, this, &TMainWindow::OnBackButton);

	m_pTimeLabel = new QLabel(this);
	m_pTimeLabel->setText(s_sTimeLabelText);

	m_pTimeLeft = new QLabel(this);

	bottomLayout->addWidget(m_pNextButton);
	bottomLayout->addWidget(m_pBackButton);
	bottomLayout->addWidget(m_pTimeLabel);
	bottomLayout->addWidget(m_pTimeLeft);

	layout->addLayout(bottomLayout);

	UpdateQuestionLayout();
}

void TMainWindow::UpdateQuestionLayout() {
	m_pQuestionNumber->setText(QString::number(m_uCurrentQuestionIndex));
	const auto& question = m_pTest->Questions[m_uCurrentQuestionIndex];
	m_pQuestionText->setText(QString::fromStdString(question.Text));

	qDeleteAll(m_vAnswers);
	m_vAnswers.clear();

	for(const auto& answer : question.Answers) {
		auto checkbox = new QCheckBox(QString::fromStdString(answer.Text));
		m_vAnswers.push_back(checkbox);
		m_pAnswersLayout->addWidget(checkbox);
	}
	m_pAnswersContents->setLayout(m_pAnswersLayout);
}

void TMainWindow::OnStartButton() {
	m_pStartButton->hide();
	qInfo() << "OnStartButton" << "\n";
}

void TMainWindow::OnNextButton() {
	m_uCurrentQuestionIndex++;
	UpdateQuestionLayout();
}

void TMainWindow::OnBackButton() {
	m_uCurrentQuestionIndex--;
	UpdateQuestionLayout();

}













