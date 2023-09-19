#include "main.h"
/**
 * rev_st - handles the %r specifer
 * @arg: argument parameter handeling
 * @c: counting paratmeter handling
 * l - lenth of string
 * y: prints string in reverse
 * @st - retrives the string argument
 */
void rev_st(va_list *arg, int *c)
{
        char *st = va_arg(*arg, char *);
        int l = 0;
        int y;

        while (st[l] != '\0')
                l++;
        for (y = l - 1; y >= 0; y--)
        {
                write(1, &st[y], 1);
                (*c)++;
        }
}
