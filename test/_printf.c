#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 *_printf - printf fun
 *@format :
 *@... :
 *Return :
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int in = 0;
	int c = 0;

	va_start(arg, format);

	    
	while (format && format[in])
	{
		if (format[in] == '%')
		{
			in++;
			switch (format[in])
			{
				case 'c':
					{
						char c = va_arg(arg, int);
						write(1, &c, 1);
						c++;
						break;
					}
				case 's':
					{
						char *str = va_arg(arg, char *);
						int k = 0;
						while (str && str[k])
						{
							write(1, &str[k], 1);
							c++;
							k++;
						}
						break;
					}
				case '%':
					{
						int k = 0;
						write(1, &format[k], 1);
						c++;
						break;
					}
				default:
					{
						break;
					}
			}
		}
		else
		{
			write(1, &format[in], 1);
			c++;
		}
		in++;
	}

	va_end(arg);

	return c;
}

