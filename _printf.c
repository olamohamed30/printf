#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>




/**
 * charola - Handles the char specifier.
 * @arg: The argument list containing the character to print.
 * @c: The character count.
 *
 * Description: This function handles the character specifier for the custom
 * printf function. It retrieves the character from the argument list, writes
 * ithe t, and increments the character count.
 */
void charola(va_list *arg, int *c)
{
	char ch;

	ch = (char) va_arg(*arg, int);
	write(1, &ch, 1);
	(*c)++;
}

/**
 * olaunsig - a fun that deals withunsigned specifier 
 * @arg: Arg list
 * @c: Count printed char
 */
void olaunsign(va_list *arg, int *c)
{
	int in;
	unsigned int n = va_arg(*arg, unsigned int);
	char buffer[20];

	itoa(n, buffer, 10);
	for ( in = 0; buffer[in]; in++)
	{
		write(1, &buffer[in], 1);
		(*c)++;
	}
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
		case 'u':
			olaunsign(arg, c);
			return (2);
		case 'X':
			olahexupper(arg, c);
			return (2);
		case 'o':
			olaoctal(arg, c);
			return (2);
		case 'x':
			olahexlower(arg, c);
			return (2);
			    
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
                        return (2);
		case 'd':
			intduaa(arg, c);
			return (2);
		case 'r':
			rev_st(arg, c);
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
