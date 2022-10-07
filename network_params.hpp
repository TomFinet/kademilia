#ifndef NETWORK_PARAMS_
#define NETWORK_PARAMS_

// size in bits of a key user for node ids and storage. 
const int KEY_SIZE = 160;

// number of parallel network calls allowed
const int ALPHA = 3;

// number of contacts stored in a bucket
const int BUCKET_SIZE = 20;

// time for a key/value pair to expire
const int T_EXPIRE = 86400;

// time after which an unaccessed bucket must be refreshed
const int T_REFRESH = 3600;

// time interval between replication events
const int T_REPLICATE = 3600;

// time after which original publisher must republish a key/value pair
const int T_REPUBLISH = 86410;

#endif