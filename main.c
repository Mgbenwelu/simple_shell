#include "shell.h"
/**
 * main - Entry Point
 * @c: argument count
 * @argv: array of pointer to strings
 * Return: 1 or 0
 */
int main(int c, char **argv)
{
	char *user_input, **rx_argv;
	ssize_t fd_check;
	int i, ex_status = 0;
	data_shell simple_shell_data;

	simple_shell_data._environ = environ;
	(void)c;
	(void)argv;

	while (1 == 1)
	{
		user_input = NULL, fd_check = 0;
		user_input = prompt_read(&fd_check);
		rx_argv = tokenization(user_input, rx_argv, fd_check);
		if (rx_argv[0] == NULL)
			continue;
		if (_strcmp(rx_argv[0], "env") == 0)
		{	free(user_input);
			_env_data(&simple_shell_data);
			free_array(rx_argv);
			continue;	}
		if (_strcmp(rx_argv[0], "exit") == 0)
		{	free(user_input);
			exit_function(rx_argv, ex_status);
			free_array(rx_argv);
			continue;
		}
		i = _env_function(rx_argv);
		if (i != 0)
		{	free(user_input);
			free_array(rx_argv);
			continue;
		}
		ex_status = execute_function(rx_argv);
		if (ex_status == 1)
			print_error(rx_argv, "not found\n");
		free(user_input);
		free_array(rx_argv);
	}
	return (0);
}
