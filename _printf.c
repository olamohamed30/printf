#include "main.h"
#include <unistd.h> 
/**
<<<<<<< HEAD
 *_printf - printf fun
 *@format :
 *@... :
 *Return :
=======
 *  * _printf- printf made by duaa and ola
 *   * @format: arg that will be added to fun
 *    * @... :
 *     *Return 
>>>>>>> d08cd5a3a915bd030de44bcd7e902ddc94f4111d
 */
 

int _printf(const char *format, ...)
{
<<<<<<< HEAD
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
=======
	/*تعريف الحجات*/
	va_list arg;
	int creturn = 0;

	va_start(arg, format);
	/*لوب */
	for (; *format; format++)
	{
		/*لو هي مش السبسيفير  اطبع وخلاص */
		if (*format != '%')
		{
			write(1, format, 1);
			creturn ++;
		}
		else
			/*  لو هي هنعمل ال سوتش علي كل حاله */
		{
			format++;
			switch (*format)
			{
				case 'c':
					/*حاله الحرف هنطبع عادي ونزود الكونت */
					char c = va_arg(arg, int);
					write(1, &c, 1);
					creturn++;
					break;
				case 's':
					{
						/*بما انه نص نفس شغل ال char بس ب لوب */
						char *string = va_arg(arg, char*);
						while (*string)
							/*لما نوصل  null terminator */
						{
							write(1, string, 1);
							creturn++;
							string++;
						}
						break;
					}
				case '%':
					{
						/*هنطبع عادي جدا ونزود الكونت*/
						write(1, format, 1);
						creturn++;
						break;
					}
				case 'd':
				case 'i':
					{
						/* duaa part = fun like itoa */
						break;
					}

				default:
					{
						/*ola still under work */
						break;
					}

			}
		}
	}

	va_end(arg);

	return creturn;
>>>>>>> d08cd5a3a915bd030de44bcd7e902ddc94f4111d
}

