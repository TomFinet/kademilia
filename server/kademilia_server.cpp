#include "kademilia_server.hpp"

/*int KademiliaServer::SendMessage(
	std::unique_ptr<Node> to,
	std::unique_ptr<Message> msg
) {

	// send the actual message to the Node
	// use the sendto function
}*/

KademiliaServer::KademiliaServer() { }


int KademiliaServer::HandlePacket(void *buffer) {
	// determines what should be done with the packet
	return 0;
}
