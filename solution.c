#include "main.h"

/**
 *find_solution - function that retrieves help messages
 *according to the builtin
 *@datash: data structure (args and input)
 *Return: Return 0
 */
int find_solution(data_shell *datash)
{

if (datash->args[1] == 0)
cd_help_general();
else if (_strcmp(datash->args[1], "setenv") == 0)
cd_help_setenv();
else if (_strcmp(datash->args[1], "env") == 0)
cd_help_env();
else if (_strcmp(datash->args[1], "unsetenv") == 0)
cd_help_unsetenv();
else if (_strcmp(datash->args[1], "help") == 0)
cd_help();
else if (_strcmp(datash->args[1], "exit") == 0)
cd_help_exit();
else if (_strcmp(datash->args[1], "cd") == 0)
cd_help_cd();
else if (_strcmp(datash->args[1], "alias") == 0)
cd_help_alias();
else
write(STDERR_FILENO, datash->args[0],
_strlen(datash->args[0]));

datash->status = 0;
return (1);
}
