#include "main.h"

/**

 *strcat_cd_help - function that concatenates the message for cd_fault_a

 *@datash: data relevant (directory)

 *@msg: message to print

 *@fault: output message

 *@ver_str: counter lines

 *Return: error message
 */
char *strcat_cd_help(data_shell *datash, char *msg, char *fault, char *ver_str)
{
char *fault_a;

_strcpy(fault, datash->av[0]);
_strcat(fault, ": ");
_strcat(fault, ver_str);
_strcat(fault, ": ");
_strcat(fault, datash->args[0]);
_strcat(fault, msg);
if (datash->args[1][0] == '-')
{
fault_a = malloc(3);
fault_a[0] = '-';
fault_a[1] = datash->args[1][1];
fault_a[2] = '\0';
_strcat(fault, fault_a);
free(fault_a);
}
else
{
_strcat(fault, datash->args[1]);
}

_strcat(fault, "\n");
_strcat(fault, "\0");
return (fault);
}

/**

 *fault_get_cd_help - fault message for cd command in get_cd_help

 *@datash: data relevant (directory)

 *Return: Fault message
 */
char *fault_get_cd_help(data_shell *datash)
{
int length, len_id;
char *fault, *ver_str, *msg;

ver_str = aux_itoa(datash->counter);
if (datash->args[1][0] == '-')
{
msg = ": Illegal option ";
len_id = 2;
}
else
{
msg = ": can't cd to ";
len_id = _strlen(datash->args[1]);
}

length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
fault = malloc(sizeof(char) * (length + 1));

if (fault == 0)
{
free(ver_str);
return (NULL);
}

fault = strcat_cd_help(datash, msg, fault, ver_str);

free(ver_str);

return (fault);
}

/**

 *fault_not_found - generic fault message for command not found

 *@datash: data relevant (counter, arguments)

 *Return: Fault message
 */
char *fault_not_found(data_shell *datash)
{
int length;
char *fault;
char *ver_str;

ver_str = aux_itoa(datash->counter);
length = _strlen(datash->av[0]) + _strlen(ver_str);
length += _strlen(datash->args[0]) + 16;
fault = malloc(sizeof(char) * (length + 1));
if (fault == 0)
{
free(fault);
free(ver_str);
return (NULL);
}
_strcpy(fault, datash->av[0]);
_strcat(fault, ": ");
_strcat(fault, ver_str);
_strcat(fault, ": ");
_strcat(fault, datash->args[0]);
_strcat(fault, ": fault\n");
_strcat(fault, "\0");
free(ver_str);
return (fault);
}
