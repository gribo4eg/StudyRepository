#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "user.h"

struct user_s
{
    char *name;
};

user_t * user_new(const char* username)
{
    user_t * user = malloc(sizeof(struct user_s));
    user->name = malloc(USERNAME * sizeof(char));
    strcpy(user->name, username);
    return user;
}

void user_free(user_t* user)
{
    free(user->name);
    free(user);
}

char * user_username(user_t* user)
{
    return user->name;
}
