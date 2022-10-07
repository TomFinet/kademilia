#include "node_id.hpp"

NodeId::NodeId() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0,1);

	for(int i=0; i<ID_SIZE; i++) {
		id_[i] = (bool) dis(gen);
	}
}

std::unique_ptr<NodeId> NodeId::Distance(const NodeId &to_id) const {
    bool dist[ID_SIZE];
	for(int i=0; i<ID_SIZE; i++) {
		dist[i] = to_id[i] ^ id_[i];
    }
    return std::make_unique<NodeId>(dist);
}