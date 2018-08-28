#include"MySocket.h"

#include <stdio.h>

#include<stdlib.h>

Server::Server(int protfamily,int type, int protocol) : Socket(protfamily,type,protocol)

{

	connect_socket_id_=-1;

}



Server::~Server() {}

	

int Server::SetListen(int max_connect_nums)

{

	return listen(monitor_socket_id_, max_connect_nums);

}



bool Server::GetAccept(struct sockaddr * servaddr)

{

	int _addr_size;

	if(servaddr==NULL) _addr_size = 0;

	else _addr_size = sizeof(*servaddr);

	connect_socket_id_ = accept(monitor_socket_id_,servaddr,NULL);

	return connect_socket_id_!=-1;

}



void Server::SetServAddr(int prot, int portfamily)

{

	memset(&servaddr_, 0, sizeof(servaddr_));

	servaddr_.sin_family = portfamily;

	servaddr_.sin_port = htons(prot);

	servaddr_.sin_addr.s_addr = htonl(INADDR_ANY);	

}

	

int Server::SendMessage(char * data,int flags)

{

	return send(connect_socket_id_,data,strlen(data),flags);

}



int Server::ReciveMessage(int flags)

{

	int temp;

	temp = recv(connect_socket_id_,buffer_,bufflen_,flags);

	buffer_[temp] = '\0';

	return temp;

}



void Server::CloseConnect()

{

	close(connect_socket_id_);

}

