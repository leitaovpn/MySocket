#include"MySocket.h"

#include<arpa/inet.h>

#include <stdio.h>

#include<stdlib.h>

Client::Client(int protfamily,int type, int protocol) : Socket(protfamily,type,protocol)

{

	

}



Client::~Client() {}

	

int Client::SetConnect()

{

	return connect(monitor_socket_id_,(struct sockaddr *)&servaddr_,sizeof(servaddr_));

}



bool Client::SetServAddr(char * ip , int prot, int portfamily)

{

	memset(&servaddr_, 0, sizeof(servaddr_));

	servaddr_.sin_family = portfamily;

	servaddr_.sin_port = htons(prot);

	return inet_pton(portfamily, ip, &servaddr_.sin_addr)<=0;

}

	

int Client::SendMessage(char * data,int flags)

{

	return send(monitor_socket_id_,data,strlen(data),flags);

}



int Client::ReciveMessage(int flags)

{

	int temp;

	temp = recv(monitor_socket_id_,buffer_,bufflen_,flags);

	buffer_[temp] = '\0';

	return temp;

} 