#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFSIZE 1024

int _printf(const char *format, ...);
void rev_st(va_list *arg, int *c);
void intduaa(va_list *arg, int *c);
void olaunsign(va_list *arg, int *c);
void olaoctal(va_list *arg, int *c);
void olahexlower(va_list *arg, int *c);
void olahexupper(va_list *arg, int *c);
char *itoa(int value, char *str, int base);


#endif
