#include "main.h"

/**
 * print_alphabet_x10 - prints all alphabets in lowercase 10 times.
 * Return: On success 1
 */
void print_alphabet_x10(void)
{
char i, j;
i = 0;
while (i < 10)
{
j = 'a';
while (j <= 'z')
{
_putchar(j);
j++;
}
_putchar('\n);
i++;
}
}
