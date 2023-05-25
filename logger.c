/*Simple logging script*/

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#include "logger.h"
static char * logging_filename = "logger.txt"; // default log filename
static int current_log_level = 0; // effects what is able to be outputed to log


void log_function(int log_level, const char * format, ...) {
    // don't log messages that are less severe than the current log level; 
    if (log_level < current_log_level) return;


    // Open the log file.
    FILE *log_file = fopen(logging_filename, "w"); // mode set to create file or overwrite any existing
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    switch (log_level) {
    case 
        break;
    
    default:
        break;
    }        
        


    fclose(log_file);
}

void set_log_file(char * filename) {
    logging_filename = filename;    
}

