#include "shell.h"

/**
 * _pt_mem - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @s: string copy to
 * @d: string to copy
 * Return: pointer to the duplicated string.
 */
char *_pt_mem(char *d, char *s)
{
	int i, len;

	if (s == NULL)
		return (NULL);

	len = 0;
	while (s[len])
		len++;

	d = malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		d[i] = s[i];
	d[i] = '\0';

	return (d);
}

/**
 * _strtok - splits a string into a series of tokens
 * @str: string to tokenize
 * @delim: delimiter
 *
 * Return: pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *saveptr;
	char *token;
	int i, j, len;

	if (str == NULL)
		str = saveptr;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	token = malloc(sizeof(char) * (len + 1));
	if (token == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				token[i] = '\0';
				saveptr = &str[i + 1];
				return (token);
			}
		}
		token[i] = str[i];
	}
	token[i] = '\0';
	saveptr = NULL;
	return (token);
}

/**
 * _getenv - searches the environment list to find the environment variable
 * @name: name of the variable to find
 *
 * Return: pointer to the value of the environment variable
 */
char *_getenv(const char *name)
{
	int i, j, len;

	if (name == NULL)
		return (NULL);

	len = 0;
	while (name[len])
		len++;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (&environ[i][j + 1]);
	}

	return (NULL);
}

