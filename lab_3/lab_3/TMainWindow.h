#ifndef TMAINWINDOW_H
#define TMAINWINDOW_H

#include <QWidget>
#include <QPushButton>

class TMainWindow : public QWidget {
	Q_OBJECT
	public:
	explicit TMainWindow(QWidget *parent = nullptr);

	signals:

	private slots:
	void OnStartButton();

	private:
	QPushButton* m_pStartButton = nullptr;

};

#endif // TMAINWINDOW_H
