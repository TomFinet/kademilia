#ifndef NODE_ID_
#define NODE_ID_

#include <memory>
#include <random>

template<const int ID_SIZE>
class NodeId {

    // node id
    bool id_[ID_SIZE];

    // constructs a NodeId object by generating
    // a uniformly random ID_SIZE-bit key.
    NodeId();

    bool operator[](const size_t i) const { return id_[i]; }
    
    inline bool operator==(const NodeId &lhs, const NodeId &rhs) {
        for(int i=0; i<ID_SIZE; i++) {
            if(lhs[i] != rhs[i]) return false;
        }
        return true;
    }

    // the distance between two nodes using the xor metric.
    std::unique_ptr<NodeId> XorDist(const NodeId &to_id) const;
}

#endif