#include "TMainWindow.h"
#include <QLayout>

static constexpr int s_iWidth = 600;
static constexpr int s_iHeight = 600;

static constexpr int s_iStartButtonWidth = 100;
static constexpr int s_iStartButtonHeight = 100;
static const QString s_sStartButtonText = "Start";

TMainWindow::TMainWindow(QWidget *parent)
	: QWidget{parent} {

	resize(s_iWidth, s_iHeight);

	m_pStartButton = new QPushButton(this);

	m_pStartButton->setFixedWidth(width());
	m_pStartButton->setFixedHeight(height());
	m_pStartButton->setText(s_sStartButtonText);

	QObject::connect(m_pStartButton, &QPushButton::clicked, this, &TMainWindow::OnStartButton);

	//m_pStartButton->;
}

void TMainWindow::OnStartButton() {
	qInfo() << "OnStartButton" << "\n";
}
