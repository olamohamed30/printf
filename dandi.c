#include "main.h"
/**
 * intduaa - handles the int specifier
 * count - counts the string bytes
 * du - retrieve the integer argument
 * buffer - hold integers as strings
 */
void intduaa(va_list *arg, int *c)
{
        char buffer[1024];
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
}
