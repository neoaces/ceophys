#pragma once
/**
 * @file Neolog
 * @brief Basic library for logging used in neophys.
 *
 */

/**
 * @typedef nlog_LogLevel
 * @brief Level of logging, ERROR < INFO < DEBUG
 *
 */
typedef enum nlog_LogLevel {
    ERROR,
    INFO,
    DEBUG
} nlog_loglevel_t;

/**
 * @typedef nlog_Logger
 * @brief Configuration struct for logger
 *
 */
typedef struct nlog_Logger {
    nlog_loglevel_t LogLevel; 
    const char* process_name;
} nlog_logger_t;

void nlog_log(const nlog_logger_t* logger_config, nlog_loglevel_t level, const char* message, ...);
const char* nlog_levelstr(nlog_loglevel_t level);
