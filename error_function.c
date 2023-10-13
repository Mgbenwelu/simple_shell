#include "shell.h"

/**
 * _eputs - Print a string to the standard error
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _eputs(char *str)
{
	int i;

	if (!(str))
	{
		return (0);
	}
	for (i = 0; str[i]; i++)
	{
		write(2, &str[i], 1);
	}

	return (i);
}
/**
 * print_error - Print an error message to the standard error
 * @av: The array of command and arguments
 * @err: The error message to be printed
 */
void print_error(char **av, char *err)
{
	_eputs(_getenv("_"));
	_eputs(": 1: ");
	_eputs(av[0]);
	_eputs(": ");
	_eputs(err);
}
