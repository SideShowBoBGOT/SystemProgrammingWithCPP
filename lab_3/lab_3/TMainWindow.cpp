#include "TMainWindow.h"
#include "TQuestionsTest.h"



static constexpr int s_iWidth = 600;
static constexpr int s_iHeight = 600;

static constexpr int s_iStartButtonWidth = 100;
static constexpr int s_iStartButtonHeight = 100;
static const QString s_sStartButtonText = "Start";

static const QString s_sPointsLabelText = "Points";
static const QString s_sNextButtonText = "Next";
static const QString s_sBackButtonText = "Back";
static const QString s_sFinishButtonText = "Finish";
static const QString s_sTimeLabelText = "Time left:";

TMainWindow::TMainWindow(const TQuestionsTest* test, QWidget *parent)
	: QWidget{parent}, m_pTest{test} {

	resize(s_iWidth, s_iHeight);

	BuildStartButton();
	BuildQuestionLayout();

	m_pResultsLabel = new QLabel(this);
	m_pResultsLabel->hide();

	m_vGivenAnswers.resize(test->Questions.size());
	for(auto i = 0; i < test->Questions.size(); ++i) {
		m_vGivenAnswers[i].assign(test->Questions[i].Answers.size(), false);
	}

	m_pQuestionNumber->hide();
	m_pQuestionText->hide();
	m_pAnswersContents->hide();
	m_pScrollArea->hide();
	m_pNextButton->hide();
	m_pBackButton->hide();
	m_pFinishButton->hide();
	m_pTimeLabel->hide();
	m_pTimeLeft->hide();

}

void TMainWindow::BuildStartButton() {
	m_pStartButton = new QPushButton(this);

	m_pStartButton->setFixedWidth(width());
	m_pStartButton->setFixedHeight(height());
	m_pStartButton->setText(s_sStartButtonText);

	QObject::connect(m_pStartButton, &QPushButton::clicked, this, &TMainWindow::OnStartButton);

	//m_pStartButton->hide();
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

	m_pScrollArea = new QScrollArea(this);
	m_pScrollArea->setWidgetResizable(true);
	m_pScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
	m_pScrollArea->setWidget(m_pAnswersContents);

	layout->addWidget(m_pScrollArea);

	auto bottomLayout = new QHBoxLayout(this);

	m_pNextButton = new QPushButton(this);
	m_pNextButton->setText(s_sNextButtonText);
	QObject::connect(m_pNextButton, &QPushButton::clicked, this, &TMainWindow::OnNextButton);

	m_pBackButton = new QPushButton(this);
	m_pBackButton->setText(s_sBackButtonText);
	QObject::connect(m_pBackButton, &QPushButton::clicked, this, &TMainWindow::OnBackButton);

	m_pFinishButton = new QPushButton(this);
	m_pFinishButton->setText(s_sFinishButtonText);
	QObject::connect(m_pFinishButton, &QPushButton::clicked, this, &TMainWindow::OnFinishButton);

	m_pTimeLabel = new QLabel(this);
	m_pTimeLabel->setText(s_sTimeLabelText);

	m_pTimeLeft = new QLabel(this);

	bottomLayout->addWidget(m_pNextButton);
	bottomLayout->addWidget(m_pBackButton);
	bottomLayout->addWidget(m_pFinishButton);

	bottomLayout->addWidget(m_pTimeLabel);
	bottomLayout->addWidget(m_pTimeLeft);

	layout->addLayout(bottomLayout);

	UpdateQuestionLayout();
}

void TMainWindow::UpdateQuestionLayout() {
	if(m_pTest->Questions.empty()) return;

	const auto& question = m_pTest->Questions[m_uCurrentQuestionIndex];

	m_pQuestionNumber->setText(
		"Number: " + QString::number(m_uCurrentQuestionIndex) + " Points: " + QString::number(question.Points));

	m_pQuestionText->setText(QString::fromStdString(question.Text));

	qDeleteAll(m_vAnswers);
	m_vAnswers.clear();

	for(const auto& answer : question.Answers) {
		auto checkbox = new QCheckBox(QString::fromStdString(answer.Text));
		QObject::connect(checkbox, &QCheckBox::stateChanged, this, &TMainWindow::SaveGivenAnswers);
		m_vAnswers.push_back(checkbox);
		m_pAnswersLayout->addWidget(checkbox);
	}
	m_pAnswersContents->setLayout(m_pAnswersLayout);
}

void TMainWindow::SaveGivenAnswers() {
	for(auto i = 0; i < m_vAnswers.size(); ++i) {
		m_vGivenAnswers[m_uCurrentQuestionIndex][i] = m_vAnswers[i]->isChecked();
	}
}

void TMainWindow::LoadGivenAnswers() {
	for(auto i = 0; i < m_vAnswers.size(); ++i) {
		m_vAnswers[i]->blockSignals(true);
		m_vAnswers[i]->setChecked(m_vGivenAnswers[m_uCurrentQuestionIndex][i]);
		m_vAnswers[i]->blockSignals(false);
	}
}

void TMainWindow::FinishTest() {
	m_pQuestionNumber->hide();
	m_pQuestionText->hide();
	m_pAnswersContents->hide();
	m_pScrollArea->hide();
	m_pNextButton->hide();
	m_pBackButton->hide();
	m_pFinishButton->hide();
	m_pTimeLabel->hide();
	m_pTimeLeft->hide();


	auto totalPoints = 0u;
	for(auto i = 0; i < m_vGivenAnswers.size(); ++i) {
		auto isCorrect = true;

		for(auto j = 0; j < m_vGivenAnswers[i].size(); ++j) {
			if(m_vGivenAnswers[i][j] != m_pTest->Questions[i].Answers[j].IsCorrect) {
				isCorrect = false;
				break;
			}
		}

		if(isCorrect) {
			totalPoints += m_pTest->Questions[i].Points;
		}
	}

	m_pResultsLabel->setText("Points: " + QString::number(totalPoints));
	m_pResultsLabel->show();
}

void TMainWindow::UpdateClock() {
	const auto now = std::chrono::system_clock::now();
	const auto diff = std::chrono::system_clock::to_time_t(now) - m_xStartTime;
	const auto diffTimePoint = std::chrono::system_clock::from_time_t(diff);
	const auto tmSeconds = std::chrono::time_point_cast<std::chrono::seconds>(diffTimePoint);
	const auto seconds = tmSeconds.time_since_epoch();

	const auto left = m_pTest->Seconds.value() - seconds;
	m_pTimeLeft->setText(QString::number(left.count()));
}

void TMainWindow::OnStartButton() {
	m_pStartButton->hide();

	if(m_pTest->Seconds) {
		const auto now = std::chrono::system_clock::now();
		m_xStartTime = std::chrono::system_clock::to_time_t(now);
		std::chrono::milliseconds millisec = std::chrono::duration_cast<std::chrono::milliseconds>(m_pTest->Seconds.value());

		QTimer::singleShot(millisec.count(), this, &TMainWindow::OnFinishButton);

		m_pTimer = new QTimer(this);
		QObject::connect(m_pTimer, &QTimer::timeout, this, &TMainWindow::UpdateClock);
		m_pTimer->start(1000);

		UpdateClock();
	}


	if(m_pTest->Questions.empty()) {
		FinishTest();
		return;
	}

	m_pQuestionNumber->show();
	m_pQuestionText->show();
	m_pAnswersContents->show();
	m_pScrollArea->show();
	m_pNextButton->show();
	m_pBackButton->show();
	m_pFinishButton->show();
	m_pTimeLabel->show();
	m_pTimeLeft->show();

	m_pFinishButton->setDisabled(true);
	m_pBackButton->setDisabled(true);
}

void TMainWindow::OnNextButton() {
	SaveGivenAnswers();

	m_uCurrentQuestionIndex++;

	UpdateQuestionLayout();
	LoadGivenAnswers();

	m_pBackButton->setDisabled(false);
	if(m_uCurrentQuestionIndex == m_pTest->Questions.size() - 1) {
		m_pNextButton->setDisabled(true);
		m_pFinishButton->setDisabled(false);
	}
}

void TMainWindow::OnBackButton() {
	SaveGivenAnswers();

	m_uCurrentQuestionIndex--;

	UpdateQuestionLayout();
	LoadGivenAnswers();

	if(m_uCurrentQuestionIndex==0) {
		m_pBackButton->setDisabled(true);
	}
	m_pNextButton->setDisabled(false);
	m_pFinishButton->setDisabled(true);
}

void TMainWindow::OnFinishButton() {
	FinishTest();
}













