#include "main.h"

/**
 * get_input - function that parses the command in the arg
 * @shell: command
 * Return: function pointer of the shell command
 */
int (*get_input(char *shell))(data_shell *)
{
	shell_t shell_commands[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; shell_commands[i].name; i++)
	{
		if (_strcmp(shell_commands[i].name, shell) == 0)
			break;
	}

	return (shell_commands[i].f);
}
