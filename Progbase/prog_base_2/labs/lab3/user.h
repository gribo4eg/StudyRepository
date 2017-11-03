#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#define USERNAME 100

typedef struct user_s user_t;

user_t * user_new(const char * username);
void user_free(user_t* user);

char * user_username(user_t* user);

#endif // USER_H_INCLUDED
