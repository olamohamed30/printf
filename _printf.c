#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * charola - Handles the char specifier.
 * @arg: The argument list containing the character to print.
 * @c: The character count.
 *
 * Description: This function handles the character specifier for the custom
 * printf function. It retrieves the character from the argument list, writes
 * it to the standard output, and increments the character count.
 */
void charola(va_list *arg, int *c)
{
	char ch;

	ch = (char) va_arg(*arg, int);
	write(1, &ch, 1);
	(*c)++;
}

/**
 * stringola - string specifier
 * @arg: Arg
 * @c: Count for printed char
 */
void stringola(va_list *arg, int *c)
{
	char *st;
	int k;

	st = va_arg(*arg, char*);

	for (k = 0; st && st[k]; k++)
	{
		write(1, &st[k], 1);
		(*c)++;
	}
}
/**
 * intduaa - handles the int specifier
 *
 * du - retrieve the integer argument
 * buffer - hold integers as strings
 * inc - initialize num of char to zero
 * start - reverse string
 * end - reverse the string
 * tmp - handles reversing the string
 */
void intduaa(va_list *arg, int *c)
{
        char buffer[50];
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

	if (du == 0)
	{
		buffer[inc++] = '0';
	}
	else
	{

        while (start < end)
        {
                temp = buffer[start];
                buffer[start++] = buffer [end];
                buffer[end--] = temp;
        }
	}

        write(1, buffer, inc);

        *c += inc;
}

/**
 * allspec - know the specifier then go to its fun
 * @format: Format string
 * @arg: Arg list
 * @c: Counter for printed characters
 * Return: Numb of char ( 1 or 2)
      */
int allspec(const char *format, va_list *arg, int *c)
{
	switch (format[1])
	{
		case 'c':
			charola(arg, c);
			return (2);
		case 's':
			stringola(arg, c);
			return (2);
		case '%':
			write(1, &format[1], 1);
			(*c)++;
			return (2);
		case 'i':
			intduaa(arg, c);
			return(2);
		case 'd':
			intduaa(arg, c);
			return (2);

		default:
			return (1);
	}
}

/**
 * _printf - printfduaa/ola fun
 * @format:  string
 * Return: Num of char
 */
int _printf(const char *format, ...)
{
	int c = 0;
	va_list arg;
	int in;

	va_start(arg, format);

	for (in = 0; format && format[in]; in++)
	{
		if (format[in] == '%')
		{
			int chprosses;

			chprosses = allspec(format + in, &arg, &c);
			in += chprosses;
			in--;

		}
		else
		{
			write(1, &format[in], 1);
			c++;
		}
	}

	va_end(arg);
	return (c);
}
