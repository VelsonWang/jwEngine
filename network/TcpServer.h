#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "TcpSocket.h"

#define DEFAULT_BACKLOG 128

class EventLoop;
class TcpServer
{
public:
	TcpServer(EventLoop * loop);

	int listen(const char * ip, int port, bool ipv6 = false);

	/*
	���ú��޷����ӽ�������Ҫ�ȴ��������ӶϿ����˳��¼�ѭ��
	*/
	void shutdown();

protected:
	
	virtual TcpSocket * createConnect() = 0;
	virtual void onConnect(TcpSocket * connect) = 0;

private:
	static void on_new_connection(uv_stream_t *server, int status);

protected:
	uv_loop_t * mLoop;
	uv_tcp_t    m_uv_tcp;
};

#endif