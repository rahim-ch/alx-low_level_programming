#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the destination file.
 * @text_content: The NULL-terminated string to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 *         -1 is returned if:
 *          - The number of arguments is incorrect (exit code 97).
 *          - The source file (file_from) does not exist or cannot be read (exit code 98).
 *          - The destination file (file_to) cannot be created or written to (exit code 99).
 *          - Closing a file descriptor fails (exit code 100).
 *         Permissions of the created file: rw-rw-r--.
 *
 * Notes:
 * - If the destination file (file_to) already exists, it will be truncated.
 * - The function reads 1,024 bytes at a time from file_from for efficiency.
 * - It is allowed to use dprintf for error messages.
 */

{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_fd - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 *
 * This function attempts to close the specified file descriptor and checks
 * for any errors. If an error occurs, it prints an error message to the
 * standard error stream and exits with code 100.
 *
 * Return: None.
 */

{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the program arguments.
 *
 * This program copies the content of one file to another. It takes two
 * command-line arguments: the source file (file_from) and the destination
 * file (file_to). If any errors occur during file operations, appropriate
 * error messages are printed to the standard error stream, and the program
 * exits with the corresponding exit codes (97, 98, 99, or 100).
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
