#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

/**
* main - Entry point of the program.
* @argc: Number of command-line arguments.
* @argv: Array of command-line argument strings.
*
* Return: 0 on success, or the corresponding error code.
*/
int main(int argc, char *argv[])
{
int fd, read_bytes;
Elf32_Ehdr header;
int i;

if (argc != 2)
{
dprintf(2, "Usage: elf_header elf_filename\n");
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(2, "Error: Cannot open file %s\n", argv[1]);
exit(98);
}

read_bytes = read(fd, &header, sizeof(header));
if (read_bytes == -1 || (size_t)read_bytes < sizeof(header))
{
dprintf(2, "Error: Cannot read from file %s\n", argv[1]);
close(fd);
exit(98);
}

if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3)
{
dprintf(2, "Error: Not an ELF file: %s\n", argv[1]);
close(fd);
exit(98);
}

printf("ELF Header:\n");
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x ", header.e_ident[i]);
printf("\n");
printf("  Class:                             ");
switch (header.e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("None\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown>\n");
}
printf("  Data:                              ");
switch (header.e_ident[EI_DATA])
{
case ELFDATANONE:
printf("None\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown>\n");
}
printf("  Version:                           %d\n", header.e_ident[EI_VERSION]);
printf("  OS/ABI:                            %d\n", header.e_ident[EI_OSABI]);
printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
printf("  Type:                              %d\n", header.e_type);
printf("  Entry point address:               %lx\n", (unsigned long)header.e_entry);

close(fd);
return (0);
}
