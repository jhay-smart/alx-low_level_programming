#include "main.c"
#include <unistd.c>

/**
 * _putchar - returns the character c to d stout
 * &c: the character to print
 * Return: on success
 */

int _putchar(char c)
{
return (write(1, &c, 1));
};
