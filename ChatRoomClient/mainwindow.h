#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <winsock2.h>
#include <QMessageBox>
#include <QMainWindow>
#include <QTextBrowser>
#include <QTableView>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrl>
#include <QJsonObject>

#include <QString>
#include <Qlist>

#include "chatthread.h"
#include "privatechatwindow.h"
#include "serversetwindow.h"

/*
*������
*����򿪵�һ�����棬�����˵�������������ã�״̬������ʾ�û�״̬��Ϣ
*�������������ң���ʱ���£��û������б�
*��½ʱ������web���������õ��û���Ϣ������״̬��Ϣ��ͷ����Ϣ��
*��������������������칦�ܿ���ʹ����
*
*
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    inline void UpdateLE();

	inline void CreatePrivateWindow();

	inline void InitSettings();

	void ShowHeadImage(const QString &szUrl);

signals:
    void SendUserInfo(SOCKET sock, QString User, QString ToUser);
    
	void PostPrivateMsg(QString msgFrom, QString msgTo, QString msg);

	void PostFileOperator(int flag, QString name, QString from, QString to, int size, QString filemd5);

	void WindowsShaking(QString from, QString to);

	//void StartReciveFile(QString fileName);

private slots:
	//�йذ�ť�������Ӧ�ۺ���
    void on_btn_login_clicked();

    void on_btn_logout_clicked();

    void on_btn_pushMessage_clicked();

	void on_btn_updateOnlineUser_clicked();

	void on_listv_onlineUser_doubleClicked(const QModelIndex &index);

	//��Ӧ�յ�ĳЩ��֮�󣬽���������ʾ��������Ĳۺ���
	void DisplayOnlineUsers(int num, QString users);

    void DisplayPublicChat_pkt(QString from, QString msg);

    void DisplayLoginReply_pkt(int code);

	//����˽�İ�
	void ProcessPrivateChat_pkt(QString msgFrom, QString msgTo, QString msg);

	void RemoveUserChatWindow(QString windowsId);

	//�����ļ������
	void ProcessFilePkt(int flag, QString name, QString from, QString to, int size, QString filemd5);

	//�����ڶ�����
	void ProcessWindowShaking(QString from, QString to);

    void SetServer(QString ip, QString port);

    void OpenServerSet();

    void replyFinished(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
	QLabel *userState;

    QNetworkAccessManager *netManager;

    QStringList onlineUser;
    QStringListModel *model;

    PrivateChatWindow *pwindow;
    ServerSetWindow *swindow;

    WSADATA wsaData;
    sockaddr_in serverAddr;
    SOCKET sClient;

    QString userName, serverIp, password, serverPort, messageContent;
	QString imageUrl;
	QString stateInfo;

    ChatThread *chatthread;

	FileTransWindow *fWindow;

	QList<QString> chatWindows;
};

#endif // MAINWINDOW_H
