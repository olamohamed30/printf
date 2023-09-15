#include <unistd.h>

/**
 *  * _printf - print string
 *   * @str: string
 *    * Return: num of characters that will be printed 
    */
int _printf(const char *str)
{
	int c = 0;

	while (*str)
	{
		write(1, str, 1);
		str++;
		c++;
	}

	return (c);
}
