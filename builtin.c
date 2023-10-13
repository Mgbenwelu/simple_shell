#include "shell.h"
/**
 * exit_function - this function exits the simple_shell
 * @rx_argv: this is the cmd entered
 * @ex_status: this is the status of the exit function
 *
 * Return: returns nothing when the shell is exited
 */
void exit_function(char **rx_argv, int ex_status)
{
	char **cmds = NULL;
	/*int status = 0;*/
	int i = 0, arg;
	const char *error_msg = "$: too many arguments\n";

	while (rx_argv[i] != NULL)
		i++;
	{

		if (i == 1)
		{
			free_array(rx_argv);
			free(cmds);
			exit(ex_status);
		}
		else if (i == 2)
		{
			arg = string_to_integer(rx_argv[1]);
			if (arg < 0)
			{
				print_error(rx_argv, "Illegal number: ");
				_eputs(rx_argv[1]);
				_eputs("\n");
				/*status = 2;*/
			}
			else
			{
				free_array(rx_argv);
				free(cmds);
				exit(arg);
			}
		}
		else
		write(STDERR_FILENO, error_msg, strlen(error_msg));
	}
}

