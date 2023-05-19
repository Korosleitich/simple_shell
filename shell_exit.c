#include "main.h"

/**

 *exit_shell - exits the shell

 *@datash: data relevant (status and args)

 *Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
unsigned int ustatus;
int is_integer;
int length;
int num;

if (datash->args[1] != NULL)
{
ustatus = _atoi(datash->args[1]);
is_integer = _isdigit(datash->args[1]);
length = _strlen(datash->args[1]);
num = ustatus > (unsigned int)INT_MAX;
if (!is_integer || length > 10 || num)
{
get_error(datash, 2);
datash->status = 2;
return (1);
}
datash->status = (ustatus % 256);
}
return (0);
}
