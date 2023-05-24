#include "main.h"

/**
 * koros - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *koros(char *in)
{
int i, num;

num = 0;
for (i = 0; in[i]; i++)
{
if (in[i] == '#')
{
if (i == 0)
{
free(in);
return (NULL);
}

if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
num = i;
}
}

if (num != 0)
{
in = _realloc(in, i, num + 1);
in[num] = '\0';
}

return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
int loop, i_eof;
char *input;

loop = 1;
while (loop == 1)
{
write(STDIN_FILENO, "^-^ ", 4);
input = read_line(&i_eof);
if (i_eof != -1)
{
input = koros(input);
if (input == NULL)
continue;

if (check_syntax_error(datash, input) == 1)
{
datash->status = 2;
free(input);
continue;
}
input = rep_var(input, datash);
loop = split_commands(datash, input);
datash->counter += 1;
free(input);
}
else
{
loop = 0;
free(input);
}
}
}
