#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
/**
* append_text_to_file - Appends text to the end of a file.
* @filename: Name of the file.
* @text_content: Text content to append to the file.
*
* Return: 1 on success, -1 on failure.
*         If filename is NULL, returns -1.
*         If text_content is NULL, does not add anything to the file.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, len, num_written;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);
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
