#include "main.h"
#include <unistd.h> 
/**
 *_printf - printf fun
 *@format :
 *@... :
 *Return :
 *  * _printf- printf made by duaa and ola
 *   * @format: arg that will be added to fun
 *    * @... :
 */
int _printf(const char *format, ...)
{
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
}
