#include "network_params.hpp"
#include "./server/kademilia_server.hpp"
//#include "node_id.hpp"
//#include "routing_table.hpp"


int main() {
	//NodeId<KEY_SIZE> our_id;
	//RoutingTable<KEY_SIZE, BUCKET_SIZE> routing_table;

	KademiliaServer server;
	server.Listen();
}