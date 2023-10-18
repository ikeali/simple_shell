#include "shell.h"
#include <stdio.h>
#include <stddef.h>


/**
 * intadd - This adds two integers
 * @int1: First integer
 * @int2: the second integer
 *
 * Return: Sum of int1 and int2.
 */
	int intadd(int int1, int int2)
	{
	return (int1 + int2);
	}

/**
 * main - Entry point of the program.
 *
 * Return: 0 (success)
 */
	int main(void)
	{
	int num1 = 10;
	int num2 = 20;
	int sum = intadd(num1, num2);

	printf("Sum: %d\n", sum);

	return (0);
	}
