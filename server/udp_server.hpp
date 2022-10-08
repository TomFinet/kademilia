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

struct ServerConfig {
    uint16_t port_;
    int max_packet_size_;
};

class UdpServer {

    // server configuration data
    struct ServerConfig config_;

	// the socket's file descriptor
	int sock_;

	// holds received packet data
	void *buffer_;

	public:

    UdpServer();
	UdpServer(const ServerConfig &config);

	~UdpServer();

	int Listen();

	virtual int HandlePacket(void *buffer) = 0;
};

#endif