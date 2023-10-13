#include "shell.h"

/**
 * _env_data - shows all environ datas
 *
 * @simple_shell_data: the environ data
 * Return: when successful returns 1
 */
int _env_data(data_shell *simple_shell_data)
{
	int i = 0;

	while (simple_shell_data->_environ[i])
	{
		int j = 0;

		while (simple_shell_data->_environ[i][j])
		{
			write(STDOUT_FILENO, &simple_shell_data->_environ[i][j], 1);
			j++;
		}

		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	simple_shell_data->status = 0;

	return (1);
}

/**
 * handle_env_data - Handle 'env' command for simple shell
 * @user_input: User input string
 * @simple_shell_data: Shell data structure
 */

void handle_env_data(char *user_input, data_shell *simple_shell_data)
{
	free(user_input);
	_env_data(simple_shell_data);
}
