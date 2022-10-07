#ifndef CONTACT_
#define CONTACT_

/*
 * Holds all data to represent a node on the network. 
 */
template<const int ID_SIZE>
class Contact {
	
    NodeId<ID_SIZE> id_;

    Contact();
    ~Contact();

    inline bool operator==(const Contact &lhs, const Contact &rhs) { return lhs.id_ == rhs.id_; }
}

#endif