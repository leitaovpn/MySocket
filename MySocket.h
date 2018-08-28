#ifndef MYSOCKET_H_

#define MYSOCKET_H_



#include<iostream>

#include<stdio.h>  

#include<stdlib.h>  

#include<string.h>  

#include<errno.h>  

#include<sys/types.h>  

#include<sys/socket.h>  

#include<netinet/in.h>

#include <unistd.h> 



#define DEFAUT_LINE 2048

//socket类

class Socket{

protected:

	struct sockaddr_in servaddr_;

	int monitor_socket_id_;

	char *buffer_;

	int bufflen_;

public:

	Socket(int protfamily = AF_INET,int type = SOCK_STREAM, int protocol=0);

	int BindSocket();

	virtual ~Socket();

	void SetBuffSize(int bufflen);

	void PrintBuffer() const;

	virtual int SendMessage(char * data, int flags=0)  = 0;

	virtual int ReciveMessage(int flags=0) = 0 ;

	virtual  void Close();

};



//server类

class Server : public Socket{

private:

	int connect_socket_id_;

public:

	Server(int protfamily = AF_INET,int type = SOCK_STREAM, int protocol=0);

	virtual ~Server();

	virtual int SendMessage(char * data, int flags=0);

	virtual int ReciveMessage(int flags=0);

	int SetListen(int max_connect_nums=10);

	bool GetAccept(struct sockaddr * servaddr = NULL);

	void SetServAddr(int prot = 8000, int portfamily = AF_INET);

	void CloseConnect();

};



//client类

class Client : public Socket{

public:

	Client(int protfamily = AF_INET,int type = SOCK_STREAM, int protocol=0);

	virtual ~Client();

	virtual int SendMessage(char * data, int flags=0);

	virtual int ReciveMessage(int flags=0);

	bool SetServAddr(char * ip , int prot = 8000, int portfamily = AF_INET);

	int SetConnect();

};

#endif