/*Simple logging script*/
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "logger.h"


static char * logging_filename = "logger.txt"; // default log filename
int current_log_level = 0; // effects what is able to be outputed to log


//todo currently the logger does not handle if the passed log level is not a specic log level enum value

void _log_function(int log_level, const char * caller_filename, int line,  const char * format, ...) {
    // don't log messages that are less severe than the current log level; 
    if (log_level < current_log_level) return;

    time_t now = time(NULL);
    char * time_str = ctime(&now); // Current time as a string
    // remove nul char from end of time string 
    time_str[strlen(time_str) - 1] = '\0';
    
    // Open the log file.
    FILE *log_file = fopen(logging_filename, "w"); // mode set to create file or overwrite any existing
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    // prints log level, time and location prefix
    switch (log_level) {
        case LOG_LEVEL_INFO:
            fprintf(log_file, "[INFO]");
            break;
        case LOG_LEVEL_DEBUG:
            fprintf(log_file, "[DEBUG]");
            break;
        case LOG_LEVEL_ERROR:
            fprintf(log_file, "[ERROR]");
            break;
        default:
            return;
            break;
    }

    fprintf(log_file, "[%s]", time_str);
    fprintf(log_file, "[%s:%d]: ", caller_filename, line);

    // C vardic function stuff; outputs the formated string to log file
    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);
    fprintf(log_file, "\n");

    fclose(log_file);
}

void set_log_file(char * filename) {
    logging_filename = filename;    
}

