#include "routing_table.hpp"

#include "udp_server.hpp"
#include "kademilia_server.hpp"

#include "key.hpp"

int main() {
	Key our_id;
	RoutingTable routing_table;

    ServerConfig config = {DEFAULT_PORT, MAX_UDP_PACKET};
	KademiliaServer server(config);
	server.Listen();
}