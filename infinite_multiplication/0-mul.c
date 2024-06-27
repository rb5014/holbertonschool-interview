#include "holberton.h"

/**
 * print_error_and_exit - print error message and exit 98
 */
void print_error_and_exit(void)
{
	int i;
	const char err_mes[] = "Error\n";

	for (i = 0; err_mes[i] != '\0'; i++)
		_putchar(err_mes[i]);
	exit(98);
}

/**
 * _atoi - convert char to int
 * @c: char to convert
 * Return: the converted char, or exit in exit function
 */
int _atoi(const char c)
{
	if ((c < '0') || (c > '9'))
		print_error_and_exit();

	return (c - '0');
}

/**
 * infinite_multiplication - multiply two positive numbers as strings
 * @n1: 1st number string
 * @n2: 2nd number string
 */
void infinite_multiplication(char *n1, char *n2)
{
	unsigned long len1 = strlen(n1);
	unsigned long len2 = strlen(n2);
	unsigned long result_len = len1 + len2;
	char *result = malloc(result_len + 1);
	long i, j;
	unsigned long k, start = 0;
	int carry, product;

	if (result == NULL)
		return;

	for (k = 0; k < result_len; k++) /* Initialize the result array */
		result[k] = '0';
	result[result_len] = '\0'; /* terminate array of char with null char */

	for (i = len1 - 1; i >= 0; i--) /* Perform multiplication digit by digit */
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			product = _atoi(n1[i]) * _atoi(n2[j]) +
						  (result[i + j + 1] - '0') + carry;

			carry = product / 10;
			result[i + j + 1] = (product % 10) + '0';
		}
		result[i] += carry;
	}
	/* Remove leading zeros */
	while (start < result_len - 1 && result[start] == '0')
		start++;
	while (result[start])
	{
		_putchar(result[start]);
		start++;
	}
	_putchar('\n');
	free(result);
}

/**
 * main - entry point of the program
 * @argc: number or arguments
 * @argv: array of string arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *n1;
	char *n2;

	if (argc != 3)
		print_error_and_exit();

	n1 = argv[1];
	n2 = argv[2];

	infinite_multiplication(n1, n2);

	return (0);
}
