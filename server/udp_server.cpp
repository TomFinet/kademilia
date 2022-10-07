#include "udp_server.hpp"

UdpServer::UdpServer(uint16_t port) {
	sock_ = socket(PF_INET, SOCK_DGRAM, IP_PROTOCOL);
	if(sock_ < 0) {
		// failed to create socket
		// handle appropriately
		fprintf(stdout, "Failed to create the socket.\n");
	}

	struct sockaddr_in addr_;
	bzero(&addr_, sizeof(struct sockaddr));
	addr_.sin_family = AF_INET;
	addr_.sin_port = htons(port);
	addr_.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sock_, (struct sockaddr *) &addr_,
		    sizeof(struct sockaddr)) < 0) {

		// failed to bind the socket
		fprintf(stdout, "Failed to bind the socket.\n");
	}

	fprintf(stdout, "Socket created successfully.\n");
}

UdpServer::~UdpServer() {
	close(sock_);
	free(buffer_);
}

int UdpServer::Listen() {

	buffer_ = malloc(sizeof(MAX_PACKET));
	struct sockaddr name;
	socklen_t len = sizeof(name);
	
	while(1) {
		int err_code = recvfrom(sock_, buffer_, MAX_PACKET, 
				0, (struct sockaddr *) &name, &len);

		if(err_code < 0) {
			// error
			perror("recfrom");
	    	exit(EXIT_FAILURE);
		}

		// make a unique pointer

		HandlePacket(buffer_);
		fprintf(stdout, "Server: got message: %s\n", (char *)buffer_);
	}

	return 0;
}