#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "logger.h"

const char* STATUSES[MAX_IN_STATUS_E] = {"ERROR", "INFO", "WARNING"};

void logger(int filedes, STATUS_E status, char* msg) {
    time_t t = time(null);
    struct tm tm = *localtime(&t);
    char buffer[2048];
    sprintf(buffer, "%s (%d-%d-%d %d:%d:%d) : | %s\n", STATUSES[status], tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, msg);
    write(filedes, buffer, strlen(buffer));
}