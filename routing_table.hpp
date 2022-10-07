#ifndef ROUTING_TABLE_
#define ROUTING_TABLE_

#include <memory>

/**
 * A list of N K-buckets, where bucket i stores
 * the closest k nodes at distance d for 2^i<= d < 2^{i+1}. 
 */
template<const int N, const int K>
class RoutingTable {

	// N buckets each of size K
	Node buckets_[N][K];

	RoutingTable();

	int AddContact(const Node &contact);

}

#endif