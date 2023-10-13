#include "shell.h"
/**
 * execute_function - execute user's command
 * @rx_argv: array to pointer of strings
 * Return: nothing
 */
int execute_function(char **rx_argv)
{
	char *usr_input, *final_cmd;
	pid_t child_process;
	int process_status = 0;

	usr_input = NULL;
	final_cmd = NULL;
	child_process = -1;
	usr_input = rx_argv[0];
	final_cmd = get_file_path(usr_input);

	if (final_cmd == NULL)
		return (1);
	if (rx_argv && access(final_cmd, X_OK) != -1)
	{
		child_process = fork();

		if (child_process == -1)
		{
			print_error(rx_argv, "command not found\n");
		}
		else if (child_process == 0)
		{

			if (execve(final_cmd, rx_argv, NULL) == -1)
				print_error(rx_argv, "command not found\n");

		}
		else
		{
			if (waitpid(child_process, &process_status, 0) == -1)
				print_error(rx_argv, "command not found\n");
		}
		if (_strcmp(final_cmd, usr_input) != 0)
			free(final_cmd);
		if (WIFEXITED(process_status))
			process_status = WEXITSTATUS(process_status);
		return (process_status);
	}
	free(final_cmd);
	return (1);
}
