#ifndef LAB2_PART2_LOGGER_H
#define LAB2_PART2_LOGGER_H

typedef enum {ERROR, INFO, WARNING, MAX_IN_STATUS_E} STATUS_E;

void logger(int filedes, STATUS_E status, char* msg);

#define null NULL
#define LOG(filedes, status, msg) logger(filedes, status, msg)



#endif //LAB2_PART2_LOGGER_H
