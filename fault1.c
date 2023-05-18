#include "main.h"

/**
 *fault_env - fault message for env in get_env.

 *@datash: data relevant (counter, arguments)

 *Return: fault message.
 */
char *fault_env(data_shell *datash)
{
int length;
char *fault;
char *kip_lim;
char *msg;

kip_lim = aux_itoa(datash->counter);
msg = ": Unable to add/remove from environment\n";
length = _strlen(datash->av[0]) + _strlen(kip_lim);
length += _strlen(datash->args[0]) + _strlen(msg) + 4;
fault = malloc(sizeof(char) * (length + 1));
if (fault == 0)
{
free(fault);
free(kip_lim);
return (NULL);
}

_strcpy(fault, datash->av[0]);
_strcat(fault, ": ");
_strcat(fault, kip_lim);
_strcat(fault, ": ");
_strcat(fault, datash->args[0]);
_strcat(fault, msg);
_strcat(fault, "\0");
free(kip_lim);

return (fault);
}
/**

 *fault_path_126 - fault message for path and failure denied permission.

 *@datash: data relevant (counter, arguments).

 *Return: The fault string.
 */
char *fault_path_126(data_shell *datash)
{
int length;
char *kip_lim;
char *fault;

kip_lim = aux_itoa(datash->counter);
length = _strlen(datash->av[0]) + _strlen(kip_lim);
length += _strlen(datash->args[0]) + 24;
fault = malloc(sizeof(char) * (length + 1));
if (fault == 0)
{
free(fault);
free(kip_lim);
return (NULL);
}
_strcpy(fault, datash->av[0]);
_strcat(fault, ": ");
_strcat(fault, kip_lim);
_strcat(fault, ": ");
_strcat(fault, datash->args[0]);
_strcat(fault, ": Permission denied\n");
_strcat(fault, "\0");
free(kip_lim);
return (fault);
}
