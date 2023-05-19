#include "main.h"

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @signal: Signal handler
 */
void get_int(int signal)
{
(void)signal;
write(STDOUT_FILENO, "\n^-^ ", 5);
}
