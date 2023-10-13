#ifndef _string_
#define _string_

int str_len(char *s);
char *str_cat(char *s1, char *s2);
char *str_cpy(char *dest, char *src);
int str_cmp(char *s1, char *s2);
char *str_dup(char *str);
int stoi(char *s);
void str_int_cat(int number, char *str);
char *mem_set(char *s, char b, unsigned int n);
#endif
