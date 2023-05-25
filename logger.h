#include <stdarg.h>

/**logging levels that control the granularity of the log*/
enum log_levels {
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_ERROR,
};

#define i LOG_LEVEL_INFO
#define d LOG_LEVEL_DEBUG
#define e LOG_LEVEL_ERROR


//Wrapper for logging_function so the application doesnt have to pass __LINE__ or __FILE__
/**
 * Macro wrapper Takes a log_level and a formatted string and writes a message to the log file.
 * 
 * By default, the log file is "logger.txt", but this can be changed with the function set_log_file().
 * 
 * The function checks the current log level against the passed log_level. If the current log level 
 * is higher, the function will not write a message. This allows control over the verbosity of the log 
 * by adjusting the current_log_level.
 * 
 * The log levels are defined as follows:
 * LOG_LEVEL_INFO  : Informational messages that demonstrate the progress of the application at coarse-grained level.
 * LOG_LEVEL_DEBUG : Fine-grained informational events that are most useful to debug an application.
 * LOG_LEVEL_ERROR : Error events that might still allow the application to continue running.
 */
#define clog(log_level, ...) _log_function(log_level, __FILE__, __func__, __LINE__, __VA_ARGS__);


void _log_function(int log_level, const char * caller_filename, const char * func_name, int line,  const char * format, ...);


/*Set the file the logger outputs too*/
void set_log_file(char * filename);
