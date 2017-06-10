
#ifndef SHAKEWINDOW_H
#define SHAKEWINDOW_H

#include <QtGui>
#include <QDialog>
#include <QObject>
#include <QTimer>

//�����Ĵ������ƶ����ڶ��ٴΣ�
enum { MaxLimitTimes = 20 };
//�����ķ��ȣ�ÿ�ζ����ı�Ĵ���λ�ô�С��
enum { MaxLimitSpace = 8 };
//������ʱ��������ʱ����
enum { ShakeSpeed = 30 };

class ShakeWindow : public QObject
{
	Q_OBJECT

public:
	ShakeWindow(QDialog *dia, QObject *parent = 0);
	~ShakeWindow();
	void startShake();

private:
	QDialog *dia;
	QTimer* m_timer;
	int m_nPosition;
	QPoint m_curPos;

	private slots:
	void slot_timerOut();
};

#endif // SHAKEWINDOW_H

