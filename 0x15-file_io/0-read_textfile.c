#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/**
* read_textfile - Reads a text file and prints it to the POSIX standard output.
* @filename: Name of the file to read.
* @letters: Number of letters to read and print.
*
* Return: The actual number of letters read and printed.
*         If the file cannot be opened or read, returns 0.
*         If filename is NULL, returns 0.
*         If write fails or does not write
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t num_read, num_written;
char *buf;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
close(fd);
return (0);
}

num_read = read(fd, buf, letters);
if (num_read == -1)
{
free(buf);
close(fd);
return (0);
}

num_written = write(STDOUT_FILENO, buf, num_read);
if (num_written == -1 || num_written != num_read)
{
free(buf);
close(fd);
return (0);
}

free(buf);
close(fd);
return (num_written);
}
