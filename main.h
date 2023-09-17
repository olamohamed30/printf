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

/**void intduaa(va_list *arg, int *c)
{
	char buffer[10];
	int du;
	int inc = 0;
	int start = 0;
	int end = inc - 1;
	char temp;

	du = va_arg(*arg, int);

	if (du < 0)
	{
		inc = 1;
	}
	else
	{
		inc = 0;
	}

	while (start < end)
	{
		temp = buffer[start];
		buffer[start++] = buffer [end];
		buffer[end--] = temp;
	}

	write(1, buffer, inc);

	*c += inc;
}*/

#endif
