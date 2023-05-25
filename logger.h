/**logging levels that control the granularity of the log*/
enum log_levels {
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_ERROR,
};

/**
 * Takes a log_level and a formatted string and writes a message to the log file.
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
void log_function(int log_level, const char * format, ...);



/*Set the file the logger outputs too*/
void set_log_file(char * filename);
