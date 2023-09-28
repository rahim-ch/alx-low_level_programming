#include "main.h"

/** * get_bit - Get the value of a bit at a given index. * @n: The number to retrieve the bit from. * @index: The index of the bit to get, starting from 0. * * Return: The value of the bit at the specified index, or -1 if an error occurred. */
int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int mask = 1;

	if (index > sizeof(n) * 8)
	{
		return (-1);
	}

	mask <<= index;

	if (mask & n)
		return (1);
	else
		return (0);
}
