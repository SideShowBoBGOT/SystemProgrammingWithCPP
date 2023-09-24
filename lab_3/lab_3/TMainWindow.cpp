#include "TMainWindow.h"
#include "TQuestionsTest.h"

#include <QLayout>

static constexpr int s_iWidth = 600;
static constexpr int s_iHeight = 600;

static constexpr int s_iStartButtonWidth = 100;
static constexpr int s_iStartButtonHeight = 100;
static const QString s_sStartButtonText = "Start";

TMainWindow::TMainWindow(const TQuestionsTest& test, QWidget *parent)
	: QWidget{parent} {

	resize(s_iWidth, s_iHeight);

	BuildStartButton();
	BuildQuestionLayout();

	//m_pStartButton->;
}



void TMainWindow::BuildStartButton() {
	m_pStartButton = new QPushButton(this);

	m_pStartButton->setFixedWidth(width());
	m_pStartButton->setFixedHeight(height());
	m_pStartButton->setText(s_sStartButtonText);

	QObject::connect(m_pStartButton, &QPushButton::clicked, this, &TMainWindow::OnStartButton);
}

void TMainWindow::BuildQuestionLayout() {
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setGeometry(QRect(0, 0, width(), height()));

	m_pQuestionNumber = new QLabel(this);
	m_pQuestionNumber->setText("Question number");
	m_pQuestionNumber->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
	layout->addWidget(m_pQuestionNumber);

	m_pQuestionText = new QLabel(this);
	m_pQuestionText->setText("What color is the sky?");
	m_pQuestionText->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
	layout->addWidget(m_pQuestionText);

	m_pAnswersArea = new QScrollArea(this);
	layout->addWidget(m_pAnswersArea);
}

void TMainWindow::OnStartButton() {
	m_pStartButton->hide();
	qInfo() << "OnStartButton" << "\n";
}
