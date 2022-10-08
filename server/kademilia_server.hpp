#ifndef KADEMILIA_SERVER_
#define KADEMILIA_SERVER_

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <memory>

#include "udp_server.hpp"

/*
 * Handles udp communication between nodes on the Kademilia network.
 */
class KademiliaServer : public UdpServer {

	public:

    KademiliaServer() : UdpServer() {}
	KademiliaServer(const ServerConfig &config) : UdpServer(config) {}

	/**
	 * Sends a message to the specified node.
	 */
	/*int SendMessage(
		std::unique_ptr<Node> to, 
		std::unique_ptr<Message> msg
	);*/

	virtual int HandlePacket(void *buffer);
};

#endif