#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFSIZE 1024

/*char *string = va_arg(arg, char*);*/
/*char c = va_arg(arg, int);*/
int _printf(const char *format, ...);

#endif
