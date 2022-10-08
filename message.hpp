#ifndef MESSAGE_
#define MESSAGE_

enum MessageType { PING, STORE, FIND_NODE, FIND_VALUE };

struct Message {
    MessageType type;
    
};

#endif