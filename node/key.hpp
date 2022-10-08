#ifndef KEY_
#define KEY_

#include <memory>
#include <random>

#include "network_params.hpp"

// used to force key parameter of constructor to be of be of correct length.
typedef struct Key_t {
    bool v[KEY_SIZE];
    bool operator[](int i) { return v[i]; }
} Key_t;

class Key {

    // node id
    bool key_[KEY_SIZE];

    public:

    Key();
    Key(const Key_t &key);
    ~Key();

    bool operator[](const size_t i) const { return key_[i]; }
    
    inline bool operator==(const Key &other) {
        for(int i=0; i<KEY_SIZE; i++) {
            if(key_[i] != other[i]) return false;
        }
        return true;
    }

    // the distance between two nodes using the xor metric.
    std::unique_ptr<Key> XorDistance(const Key &to_key) const;
};

#endif