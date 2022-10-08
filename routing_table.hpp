#ifndef ROUTING_TABLE_
#define ROUTING_TABLE_

#include <memory>

#include "network_params.hpp"
#include "contact.hpp"


class RoutingTable {

	Contact buckets_[KEY_SIZE][BUCKET_SIZE];

    public:

	RoutingTable();
    ~RoutingTable();

	int AddContact(const Contact &contact);
};

#endif