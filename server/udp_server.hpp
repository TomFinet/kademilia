#ifndef UDP_SERVER_
#define UDP_SERVER_

#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

#include <sys/un.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#include <errno.h>
#include <unistd.h>

class UdpServer {

	static const uint16_t DEFAULT_PORT = 5555;
	static const size_t MAX_PACKET = 65536; 
	static const int IP_PROTOCOL = 0;

	// the socket's file descriptor
	int sock_;

	// holds received packet data
	void *buffer_;

	public:

	UdpServer(uint16_t port=DEFAULT_PORT);

	~UdpServer();

	int Listen();

	virtual int HandlePacket(void *buffer) = 0;
};

#endif