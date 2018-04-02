#ifndef SERVERSET_H
#define SERVERSET_H

#include <QDialog>
#include <QString>
#include <QSettings>

namespace Ui {
class ServerSetWindow;
}

/*
*���������ô��ڣ������޸ķ�������ip��ַ�Ͷ˿ںţ�
*������Ϊini�����ļ�
*
*/
class ServerSetWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ServerSetWindow(QWidget *parent = 0);
    ~ServerSetWindow();

signals:
    void serverSet(QString serverIp, QString serverPort);

private slots:
    void on_btn_ok_clicked();

    void on_btn_cancle_clicked();

private:
    Ui::ServerSetWindow *ui;

    QString serverIp, serverPort;

};

#endif // SERVERSET_H
