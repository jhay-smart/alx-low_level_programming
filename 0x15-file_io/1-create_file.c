#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
/**
* create_file - Creates a file and writes text content to it.
* @filename: Name of the file to create.
* @text_content: Text content to write to the file.
*
* Return: 1 on success, -1 on failure.
*         If filename is NULL, returns -1.
*         If text_content is NULL, creates an empty file.
*/
int create_file(const char *filename, char *text_content)
{
int fd, len, num_written;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content == NULL)
{
close(fd);
return (1);
}

for (len = 0; text_content[len]; len++)
;

num_written = write(fd, text_content, len);
close(fd);

if (num_written == -1 || num_written != len)
return (-1);

return (1);
}
