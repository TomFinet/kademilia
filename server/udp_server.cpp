#include "udp_server.hpp"

UdpServer::UdpServer(const ServerConfig &config) {
    config_ = config;
	sock_ = socket(PF_INET, SOCK_DGRAM, 0);
	if(sock_ < 0) {
		// failed to create socket
		// handle appropriately
		fprintf(stdout, "Failed to create the socket.\n");
	}

	struct sockaddr_in addr_;
	bzero(&addr_, sizeof(struct sockaddr));
	addr_.sin_family = AF_INET;
	addr_.sin_port = htons(config.port_);
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
	buffer_ = malloc(sizeof(config_.max_packet_size_));
	struct sockaddr name;
	socklen_t len = sizeof(name);
	
	while(1) {
		int err_code = recvfrom(sock_, buffer_, config_.max_packet_size_, 
				0, (struct sockaddr *) &name, &len);

		if(err_code < 0) {
			// error
			perror("recvfrom");
	    	exit(EXIT_FAILURE);
		}

		// make a unique pointer
        fprintf(stdout, "Server: got message: %s\n", (char *)buffer_);
		HandlePacket(buffer_);
	}

	return 0;
}