#include "shell.h"

/**
 *_setenv - Set a new environment variable or modify an existing one
 * @args: Array of arguments [VARIABLE, VALUE]
 * Return: 0 on success, -1 on failure
 */
int _setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE\n", 29);
		return (-1);
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		print_error(args, "Failed to set environment variable\n");
		return (-1);
	}

	return (0);
}

/**
 *_unsetenv - Remove an environment variable
 * @args: Array of arguments [VARIABLE]
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
		return (-1);
	}

	if (getenv(args[1]) == NULL)
	{
		return (0);
	}
	unsetenv(args[1]);

	return (0);
}

/**
 * _env_function - Handle setenv, unsetenv, and echo commands
 * @args: Array of arguments
 * Return: 1 if handled, 0 if not handled
 */
int _env_function(char **args)
{
	char *value;

	if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL)
			return (-1);
		if (_setenv(args) == -1)
			print_error(args, "Failed to set environment variable\n");
		return (1);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL)
		{
			write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
			return (-1);
		}
		if (unsetenv(args[1]) == -1)
		{	write(STDERR_FILENO, "Failed to unset environment variable\n", 37);
			return (-1);
		}
		_unsetenv(args);
		return (1);
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		if (args[1] == NULL)
		{	write(STDERR_FILENO, "Usage: echo VARIABLE\n", 21);
			return (-1);
		}
		value = getenv(args[1]);
		if (value != NULL)
		{	write(STDOUT_FILENO, value, strlen(value));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			write(STDOUT_FILENO, "$\n", 2);
		return (1);
	}
	return (0);
}
