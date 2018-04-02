#ifndef __ZQQ_PROTOCOL__H
#define __ZQQ_PROTOCOL__H

#define LOGIN_PKT			    100
#define LOGOUT_PKT			    101
#define LOGIN_REPLY_PKT		    102
#define PUBLIC_CHAT_PKT		    103
#define PRIVATE_CHAT_PKT	    104
#define UPDATE_ONLINEUSER_PKT	105
#define WINDOWSSHAKING_PKT	    106
#define TRANSMITFILECMD_PKT    107

#define PUBLIC_CHAT_HEAD    (sizeof(Header) + 20)
#define PRIVATE_CHAT_HEAD   (sizeof(Header) + 40)


typedef struct Header
{
	int length;
	int type;
}Header;

typedef struct LoginPkt
{
	Header header;
	char   userName[20];
	char   password[20];
}LoginPkt;

typedef struct LogoutPkt
{
	Header header;
	char   userName[20];
}LogoutPkt;

#define LOGIN_FAIL	  0
#define LOGIN_SUCCESS 1

typedef struct LoginRelpyPkt
{
	Header header;
	int		retCode;
}LoginRelpyPkt;

typedef struct PublicChatMsg
{
	Header header;
	char   from[20];
	char   message[512];
}PublicChatMsg;

typedef struct PrivateChatMsg
{
	Header header;
	char   from[20];
	char   to[20];
	char   message[512];
}PrivateChatMsg;

typedef struct WindowShakingPkt
{
	Header header;
	char   from[20];
	char   to[20];
}WindowShakingPkt;

//huo qu zaixian liebiao
typedef struct RequestOnlineUserPkt
{
    Header header;
    int ReqNumber;
}RequestOnlineUserPkt;

typedef struct ResponseOnlineUserPkt
{
    Header header;
    int OnlineNum;
	int isAll;
    char users[1024];
}ResponsetOnlineUserPkt;


/*
���ļ���
1.�ͻ��˷���FILE_SEND
2.����˸����������FILE_RECV/ FILE_EXIST/ FILE_SERVERERROR
(1)�ͻ����յ�FILE_RECV�������ݶ˿ڷ�FILE_SEND������ʼ���ļ�
(2)�ͻ����յ�FILE_EXIST����ʾ���ͳɹ�
(3)�ͻ����յ�FILE_SERVERERROR����ʾ����ʧ��
3.�ļ��������ʱ�ر����ݶ˿�

���ļ���
1.����˷���FILE_SEND
2.�ͻ����յ�FILE_SEND�������ݶ˿ڷ�FILE_RECV
3.����������ݶ˿��յ�FILE_RECV���Ϳ�ʼ���ļ�
4.�ļ��������ʱ�ر����ݶ˿�
5.�ͻ��˷���FILE_RECVSUCCESS
6.����˰�FILE_RECVSUCCESSת�������ͷ�
7.���ͷ���ʾ�Է����յ��ļ�
*/
//�����Ǵ��ļ��������ֶεĶ���
#define FILE_SEND         101  //�������ļ�
#define FILE_RECV         102  //��������ļ�
#define FILE_RECVSUCCESS  200  //�����ļ��ɹ�
#define FILE_EXIST        304  //�ļ��Ѿ�����
#define FILE_NOTFOUND     404  //�ļ��Ѿ�����
#define FILE_SERVERERROR  500  //����˲�����

//������˿ڵİ���ʽ
typedef struct TransmitFlieCmdPkt
{
    Header header;
    int    cmd;       //������
    int    fileSize;  //�ļ���С
    int    recvSize;  //�������ϵ�������
    char   from[20];
    char   to[20];
    char   md5[32];   //32λMD5У����
    char   filename[256];
}TransmitFlieCmdPkt;

//zhegebao yongyu yanzheng
//�����ݶ˿ڵİ���ʽ(�ڷ�����֮ǰ��)
//�����cmdֻ����FILE_SEND��FILE_RECV
typedef struct FileHeader
{
	int    cmd;       //�����֣���or����
	int    fileSize;  //�ļ���С
	int    recvSize;  //�������ϵ�������
	char   from[20];
	char   to[20];
	char   md5[32];   //32λMD5У����
}FileHeader;


#endif //__ZQQ_PROTOCOL__H
