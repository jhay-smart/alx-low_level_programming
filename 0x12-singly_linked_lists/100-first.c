#include <stdio.h>

/**
* before_main - Prints a specific message before the main function is executed.
*
* Description: This function is executed before the main function and
* prints a specific message.
*/
void before_main(void) __attribute__((constructor));
void before_main(void)
{
printf("You're beat! and yet, you must allow,\n"
"I bore my house upon my back!\n");
}
