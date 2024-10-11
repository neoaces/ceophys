#include <assert.h>
#include <neolog/neolog.h>
#include "hmap.h"

static const nlog_logger_t logger_config = {.LogLevel = DEBUG, .process_name = "neolib"};

size_t _hash(char* key, size_t array_size) {
    size_t sum = 0;
    size_t req_arr = array_size - 1;
    char* key_copy = key;
    assert(key_copy != NULL);

    while ( *key_copy != '\0' ) {
	sum += *key_copy;
	key_copy++;
    }
    
    size_t hash = sum % req_arr;
    assert(hash <= req_arr);

    nlog_log(&logger_config, DEBUG, "Calculated hash for '%s', %d", key, hash);

    return hash;
}
