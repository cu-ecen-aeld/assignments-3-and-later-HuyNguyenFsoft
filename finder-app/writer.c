#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

void write_data_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file for writing");
        return;
    }

    int ret = fprintf(file, "%s", data);
    if (ret < 0) {
        syslog(LOG_ERR, "Error writing data to file");
        fclose(file);
        return;
    }
    else{
        syslog(LOG_DEBUG, "Writing %s to %s", data, filename); 
    }
    
    fclose(file);
    return;
}

int main(int argc, char *argv[]) {
    openlog("my_app", LOG_CONS | LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Error: Missing arguments");
        return 1;
    }
    
    write_data_to_file(argv[1], argv[2]);
    closelog();

    return 0;
}

