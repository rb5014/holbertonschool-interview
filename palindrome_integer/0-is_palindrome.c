#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>
#define _OPEN_SYS_ITOA_EXT
/**
 * is_palindrome - checks whether or not a given unsigned integer
 * is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long remainder, reverse = 0, n_original = n;

	while (n != 0)
	{
		remainder = n % 10;
		reverse = reverse * 10 + remainder;
		n /= 10;
	}
	return (reverse == n_original ? 1 : 0);
}
