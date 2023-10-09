#include "shell.h"
#include <stdio.h>

/**
 * _intadd - Adds two integers
 * @int1: the first integer
 * @int2: the second integer
 * Return: The sum of int1 and int2
 */
	int _intadd(int int1, int int2);

	int(void)
	{
	int num1 = 10;
	int num2 = 20;
	int sum = _intadd(num1, num2);

	printf("Sum: %d\n", sum);

	return (0);
	}

	int _intadd(int int1, int int2)
	{
	return (int1 + int2);
	}
