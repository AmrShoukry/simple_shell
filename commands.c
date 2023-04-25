#include "all.h"

/**
 * _exit_ - Function.
 *
 * @status: parameter1
 *
 * Return: value.
 */

int _exit_(char *status)
{
	int number = 0;
	int index = 0;

	if (status == NULL)
	{
		return (20030803);
	}

	while (status[index] != '\0')
	{
		if (status[index] >= '0' && status[index] <= '9')
		{
			number = (number * 10) + (status[index] - 48);
		}
		else
		{
			return (1);
		}
		index++;
	}
	if (number == 0)
	{
		return (20030803);
	}
	return (number);
}
