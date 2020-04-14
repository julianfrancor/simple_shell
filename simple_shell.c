#include "shellhead.h"

/**
 * main - main function of
 * program simple_shell
 * Return: on succes return 0.
 */
int main(void)
{
	char *lineptr = NULL, **args;
	int status = 0;

	while (status == 0)
	{
		/*prints prompt*/
		write(STDOUT_FILENO, "$ ", 2);

		lineptr = _getline();
		if (lineptr == 0)
		{
			free(lineptr);
			continue;
		}
		args = tokenizer(lineptr, TOK_DELIMITER);
		status = execute(args);
		free(args);
		free(lineptr);
	}
	return (0);
}