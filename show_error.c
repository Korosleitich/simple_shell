#include "main.h"

/**
 *show_fault - calls the error according to the builtin
 *syntax or permission
 *@datash: data structure that contains arguments
 *@eval: fault value
 *Return: fault
 */
int show_fault(data_shell *datash, int eval)
{
char *fault;

switch (eval)
{
case -1:
fault = fault_env(datash);
break;
case 126:
fault = fault_path_126(datash);
break;
case 127:
fault = fault_not_found(datash);
break;
case 2:
if (_strcmp("exit", datash->args[0]) == 0)
fault = fault_exit_shell(datash);
else if (_strcmp("cd", datash->args[0]) == 0)
fault = fault_get_cd(datash);
break;
}

if (fault)
{
write(STDERR_FILENO, fault, _strlen(error));
free(fault);
}

datash->status = eval;
return (eval);
}
