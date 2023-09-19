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

/**
 * intduaa - handles the int specifier
 * count - counts the string bytes
 * du - retrieve the integer argument
 * buffer - hold integers as strings
 * inc - initialize num of char to zero
 * start - reverse string
 * end - reverse the string
 * tmp - handles reversing the string
 
void intduaa(va_list *arg, int *c)
{
        char buffer[20];
        int du = va_arg(*arg, int);
        int count = 0;

        if (du < 0)
        {
                write(1, "-", 1);
                (*c)++;
                du = -du;
        }
        if (du == 0)
        {
                write(1, "0", 1);
                (*c)++;
        }
        else
        {
                while (du > 0)
                {
                        buffer[count++] = '0' + du % 10;
                        du /= 10;
                }
                while (count > 0)
                {
                        write(1, &buffer[--count], 1);
                        (*c)++;
                }
        }
}*/

#endif
