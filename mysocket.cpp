#include<iostream>

#include<stdio.h>

#include<stdlib.h>

#include"MySocket.h"



Socket::Socket(int protfamily,int type, int protocol)

{

	bufflen_ = DEFAUT_LINE;

	buffer_ = new char[bufflen_];

	monitor_socket_id_ = socket(protfamily,type,protocol);

	memset(&servaddr_, 0, sizeof(servaddr_));

}



Socket::~Socket()

{

	delete [] buffer_;

}



int Socket::BindSocket()

{

	return bind(monitor_socket_id_,(struct sockaddr *)&servaddr_,sizeof(servaddr_));

}



void Socket::SetBuffSize(int bufflen)

{

	bufflen_ = bufflen;

	delete [] buffer_;

	buffer_ = new char[bufflen_];

}



void Socket::PrintBuffer() const

{

	printf("The buffer is : %s \n",buffer_);

}



void Socket::Close()

{

	close(monitor_socket_id_);

}