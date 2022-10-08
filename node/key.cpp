#include "key.hpp"

Key::Key() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0,1);

	for(int i=0; i<KEY_SIZE; i++) {
		key_[i] = (bool) dis(gen);
	}
}

Key::~Key() {}

Key::Key(const Key_t &key) {
    for(int i=0; i<KEY_SIZE; i++) {
        key_[i] = key.v[i];
    }
}

std::unique_ptr<Key> Key::XorDistance(const Key &to_key) const {
    Key_t distance;
	for(int i=0; i<KEY_SIZE; i++) distance.v[i] = key_[i] ^ to_key[i];
    return std::make_unique<Key>(distance);
}