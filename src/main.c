#include <neolib/hmap.h>
#include <neolog/neolog.h>

static const nlog_logger_t logger_config = {.LogLevel = DEBUG, "neophys"};

int main(void) {
    nlog_log(&logger_config, DEBUG, "Test", 5);
    
    char* key = "jesus h. christ";
    size_t hash = _hash(key, 51);
}
