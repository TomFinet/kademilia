#ifndef CONTACT_
#define CONTACT_

#include "key.hpp"

/*
 * Holds all data to represent a node on the network. 
 */
class Contact {
	
    Key id_;

    public:

    Contact();
    ~Contact();

    inline bool operator==(const Contact &other) { return id_ == other.id_; }
};

#endif