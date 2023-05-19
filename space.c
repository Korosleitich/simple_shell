#include "main.h"

/**

 *get_space - assigns the spaceptr var for get_line

 *@spaceptr: Buffer that stores the input str

 *@buffer: str that is been called to space

 *@n: size of space

 *@j: size of buffer
 */
void get_space(char **spaceptr, size_t *n, char *buffer, size_t j)
{

if (*spaceptr == NULL)
{
if (j > BUFSIZE)
*n = j;
}
else if (*n < j)
{
if (j > BUFSIZE)
*n = j;
else
*n = BUFSIZE;
spaceptr = buffer;
}
else
{
_strcpy(spaceptr, buffer);
free(buffer);
}
}
/

get_line - Read input from stream

@spaceptr: buffer that stores the input

@n: size of spaceptr

@stream: stream to read from

Return: The number of bytes
*/
ssize_t get_line(char **spaceptr, size_t *n, FILE *stream)
{
int i;
static ssize_t input;
ssize_t retval;
char *buffer;
char t = 'z';

if (input == 0)
fflush(stream);
else
return (-1);
input = 0;

buffer = malloc(sizeof(char) * BUFSIZE);
if (buffer == 0)
return (-1);
while (t != '\n')
{
i = read(STDIN_FILENO, &t, 1);
if (i == -1 || (i == 0 && input == 0))
{
free(buffer);
return (-1);
}
if (i == 0 && input != 0)
{
input++;
break;
}
if (input >= BUFSIZE)
buffer = _realloc(buffer, input, input + 1);
buffer[input] = t;
input++;
}
buffer[input] = '\0';
get_space(spaceptr, n, buffer, input);
retval = input;
if (i != 0)
input = 0;
return (retval);
}
